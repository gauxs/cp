#!/bin/bash

# Reset Progress Script
# This script resets all checkboxes in the repository to unchecked state

echo "🔄 Resetting all progress checkboxes..."

# Function to reset checkboxes in a file
reset_checkboxes() {
    local file="$1"
    if [ -f "$file" ]; then
        # Replace checked checkboxes with unchecked ones
        sed -i '' 's/- \[x\]/- [ ]/g' "$file"
        sed -i '' 's/- \[X\]/- [ ]/g' "$file"
        echo "✅ Reset checkboxes in: $file"
    fi
}

# Reset main README
reset_checkboxes "README.md"

# Reset sorting README
reset_checkboxes "algorithms/sort/README.md"

# Reset other algorithm READMEs (if they exist)
find algorithms -name "README.md" -type f | while read -r file; do
    reset_checkboxes "$file"
done

# Reset data structure READMEs (if they exist)
find data_structures -name "README.md" -type f | while read -r file; do
    reset_checkboxes "$file"
done

# Reset language READMEs (if they exist)
find language -name "README.md" -type f | while read -r file; do
    reset_checkboxes "$file"
done

# Update progress counters to 0
echo "📊 Updating progress counters..."

# Update sorting progress
if [ -f "algorithms/sort/README.md" ]; then
    sed -i '' 's/\*\*Beginner Level\*\*: [0-9]*\/[0-9]* completed/\*\*Beginner Level\*\*: 0\/3 completed/g' "algorithms/sort/README.md"
    sed -i '' 's/\*\*Intermediate Level\*\*: [0-9]*\/[0-9]* completed/\*\*Intermediate Level\*\*: 0\/4 completed/g' "algorithms/sort/README.md"
    sed -i '' 's/\*\*Advanced Level\*\*: [0-9]*\/[0-9]* completed/\*\*Advanced Level\*\*: 0\/3 completed/g' "algorithms/sort/README.md"
    sed -i '' 's/\*\*Overall Progress\*\*: [0-9]*\/[0-9]* completed ([0-9]*%)/\*\*Overall Progress\*\*: 0\/10 completed (0%)/g' "algorithms/sort/README.md"
fi

# Update main README progress
if [ -f "README.md" ]; then
    sed -i '' 's/\*\*Completed Topics\*\*: [0-9]*\/[0-9]* ([0-9]*%)/\*\*Completed Topics\*\*: 0\/15 (0%)/g' "README.md"
    sed -i '' 's/\*\*Total Problems Solved\*\*: [0-9]*/\*\*Total Problems Solved\*\*: 0/g' "README.md"
    sed -i '' 's/\*\*Last Reset\*\*: .*/\*\*Last Reset\*\*: '"$(date '+%Y-%m-%d %H:%M:%S')"'/g' "README.md"
fi

echo "🎉 All progress has been reset!"
echo "📅 Reset timestamp: $(date '+%Y-%m-%d %H:%M:%S')"
echo ""
echo "You can now start fresh with your preparation! 🚀"
