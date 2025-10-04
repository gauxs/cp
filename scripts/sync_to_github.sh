#!/bin/bash

# Sync Markdown Checklists to GitHub Issues/Projects
# This script creates GitHub issues from your markdown checkboxes

echo "🔄 Syncing markdown checkboxes to GitHub Issues..."
echo "=================================================="
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

# Function to create issues from markdown file
create_issues_from_markdown() {
    local file="$1"
    local topic="$2"
    local difficulty="$3"
    
    if [ ! -f "$file" ]; then
        echo "⚠️  File not found: $file"
        return
    fi
    
    echo "📝 Processing: $file"
    
    # Extract problems from markdown
    grep "^- \[ \].*\*\*.*\*\*" "$file" | while read -r line; do
        # Extract problem name and URL
        problem_name=$(echo "$line" | sed 's/^- \[ \] \*\*\(.*\)\*\*.*/\1/')
        problem_url=$(echo "$line" | sed 's/.*\[\(.*\)\](\(.*\)).*/\2/')
        
        if [ -n "$problem_name" ] && [ "$problem_name" != "$line" ]; then
            echo "  📋 Creating issue: $problem_name"
            
            # Create GitHub issue
            gh issue create \
                --title "$problem_name" \
                --body "**Topic:** $topic
**Difficulty:** $difficulty
**URL:** $problem_url
**Status:** Not Started

---
*This issue was auto-generated from markdown checkboxes*" \
                --label "$difficulty,$topic" \
                --assignee "@me" || echo "    ⚠️  Failed to create issue"
        fi
    done
}

# Create issues for sorting problems
echo "🔢 Creating Sorting Algorithm Issues..."
create_issues_from_markdown "algorithms/sort/README.md" "sorting" "beginner"

# Create issues for other topics (when they exist)
echo ""
echo "🔍 Creating Search Algorithm Issues..."
create_issues_from_markdown "algorithms/search/README.md" "search" "beginner"

echo ""
echo "🌐 Creating Graph Algorithm Issues..."
create_issues_from_markdown "algorithms/graph/README.md" "graph" "intermediate"

echo ""
echo "✅ Sync completed!"
echo ""
echo "📊 Next steps:"
echo "1. Go to your GitHub repository"
echo "2. Click on 'Projects' tab"
echo "3. Create a new project with columns: 'To Do', 'In Progress', 'Done', 'Skipped'"
echo "4. Add the created issues to your project"
echo "5. Use the project board to track progress visually"
echo ""
echo "🔄 To reset progress: Move all issues back to 'To Do' column"
