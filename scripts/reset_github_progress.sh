#!/bin/bash

# Reset GitHub Project Progress
# This script resets all issues back to "To Do" status

echo "🔄 Resetting GitHub Project Progress..."
echo "======================================"
echo ""

# Check if GitHub CLI is installed
if ! command -v gh &> /dev/null; then
    echo "❌ GitHub CLI (gh) is not installed."
    echo "Please install it: https://cli.github.com/"
    exit 1
fi

# Check if user is authenticated
if ! gh auth status &> /dev/null; then
    echo "❌ Not authenticated with GitHub."
    echo "Please run: gh auth login"
    exit 1
fi

# Get repository info
REPO=$(gh repo view --json nameWithOwner -q .nameWithOwner)
echo "📁 Repository: $REPO"
echo ""

# Function to reset issues by label
reset_issues_by_label() {
    local label="$1"
    echo "🔄 Resetting issues with label: $label"
    
    # Get all issues with the label
    gh issue list --label "$label" --state all --json number,title --jq '.[] | "\(.number) \(.title)"' | while read -r issue_num title; do
        if [ -n "$issue_num" ]; then
            echo "  📝 Resetting: #$issue_num - $title"
            
            # Reopen the issue if it's closed
            gh issue reopen "$issue_num" 2>/dev/null || true
            
            # Add a comment about reset
            gh issue comment "$issue_num" --body "🔄 **Reset for new preparation cycle**

This issue has been reset and is ready for a fresh attempt.

---
*Reset on: $(date '+%Y-%m-%d %H:%M:%S')*" 2>/dev/null || true
        fi
    done
}

# Reset issues by difficulty level
echo "🎯 Resetting by difficulty levels..."
reset_issues_by_label "beginner"
reset_issues_by_label "intermediate" 
reset_issues_by_label "advanced"

# Reset issues by topic
echo ""
echo "📚 Resetting by topics..."
reset_issues_by_label "sorting"
reset_issues_by_label "search"
reset_issues_by_label "graph"
reset_issues_by_label "dp"
reset_issues_by_label "greedy"

echo ""
echo "✅ GitHub progress reset completed!"
echo ""
echo "📊 Next steps:"
echo "1. Go to your GitHub project board"
echo "2. Move all issues back to 'To Do' column"
echo "3. Clear any old comments if needed"
echo "4. Start fresh with your preparation!"
echo ""
echo "💡 Tip: You can also archive the current project and create a new one for each preparation cycle."
