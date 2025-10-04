#!/bin/bash

# Progress Report Script
# This script generates a detailed progress report

echo "📊 Generating Progress Report..."
echo "=================================="
echo ""

# Function to count checkboxes in a file
count_checkboxes() {
    local file="$1"
    if [ -f "$file" ]; then
        local total=$(grep -c "^- \[" "$file" 2>/dev/null || echo "0")
        local completed=$(grep -c "^- \[x\]" "$file" 2>/dev/null || echo "0")
        local skipped=$(grep -c "^- \[-\]" "$file" 2>/dev/null || echo "0")
        echo "${completed},${skipped},${total}"
    else
        echo "0,0,0"
    fi
}

# Count main README progress
main_stats=$(count_checkboxes "README.md")
IFS=',' read -r main_completed main_skipped main_total <<< "$main_stats"

echo "🏠 Main Repository Progress:"
echo "  ✅ Completed: $main_completed"
echo "  ⏭️  Skipped: $main_skipped"
echo "  📝 Total: $main_total"
echo ""

# Count sorting progress
sort_stats=$(count_checkboxes "algorithms/sort/README.md")
IFS=',' read -r sort_completed sort_skipped sort_total <<< "$sort_stats"

echo "🔢 Sorting Algorithm Progress:"
echo "  ✅ Completed: $sort_completed"
echo "  ⏭️  Skipped: $sort_skipped"
echo "  📝 Total: $sort_total"
echo ""

# Calculate overall progress
total_completed=$((main_completed + sort_completed))
total_skipped=$((main_skipped + sort_skipped))
total_problems=$((main_total + sort_total))
total_remaining=$((total_problems - total_completed - total_skipped))

echo "📈 Overall Statistics:"
echo "  ✅ Completed: $total_completed"
echo "  ⏭️  Skipped: $total_skipped"
echo "  ⏳ Remaining: $total_remaining"
echo "  📝 Total: $total_problems"
echo ""

# Calculate percentage
if [ $total_problems -gt 0 ]; then
    completion_percentage=$((total_completed * 100 / total_problems))
    echo "  📊 Completion Rate: $completion_percentage%"
else
    echo "  📊 Completion Rate: 0%"
fi

echo ""

# Show recent activity (if git is available)
if command -v git &> /dev/null; then
    echo "🕒 Recent Activity:"
    git log --oneline --since="1 week ago" | head -5 || echo "  No recent commits"
    echo ""
fi

# Show next recommended topics
echo "🎯 Recommended Next Steps:"
if [ $sort_completed -lt 3 ]; then
    echo "  • Focus on Sorting algorithms (only $sort_completed/10 completed)"
elif [ $main_completed -lt 5 ]; then
    echo "  • Move to other algorithm topics"
else
    echo "  • Great progress! Consider advanced topics or system design"
fi

echo ""
echo "💡 Tip: Use './scripts/reset_progress.sh' to start fresh when beginning a new preparation cycle!"