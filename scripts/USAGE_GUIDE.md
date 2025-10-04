# 📋 Progress Tracker Usage Guide

This guide explains how to use the interactive checklist system for tracking your competitive programming and interview preparation progress.

## 🚀 Quick Start

### 1. Reset All Progress (Start Fresh)
```bash
./scripts/reset_progress.sh
```
This clears all checkboxes and resets progress counters to 0. Perfect for starting a new preparation cycle!

### 2. Check Your Progress
Use GitHub Projects UI to view your progress with visual charts and metrics.


## 📊 How to Use Checkboxes

### Marking Problems as Complete
- Open any README file (e.g., `algorithms/sort/README.md`)
- Find the problem you want to mark as complete
- Change `- [ ]` to `- [x]` (or `- [X]`)

**Example:**
```markdown
# Before
- [ ] **[Sort an Array](https://leetcode.com/problems/sort-an-array/)**

# After (completed)
- [x] **[Sort an Array](https://leetcode.com/problems/sort-an-array/)**
```

### Marking Problems as Skipped
- Change `- [ ]` to `- [-]` to mark as skipped

**Example:**
```markdown
# Skipped
- [-] **[Very Hard Problem](https://leetcode.com/problems/very-hard/)**
```

## 🎯 Progress Tracking Features

### 1. Individual Topic Progress
Each topic (like Sorting) shows:
- **Beginner Level**: X/3 completed
- **Intermediate Level**: X/4 completed  
- **Advanced Level**: X/3 completed
- **Overall Progress**: X/10 completed (X%)

### 2. Main Repository Overview
The main README shows:
- All major topics with completion status
- Overall completion percentage
- Quick action buttons
- Last reset timestamp

### 3. Visual Progress Tracking
- Progress bars in HTML tracker
- Color-coded completion status
- Real-time statistics

## 🔧 Available Scripts

| Script | Purpose | Usage |
|--------|---------|-------|
| `reset_progress.sh` | Clear all checkboxes | `./scripts/reset_progress.sh` |
| `sync_to_github.sh` | Create GitHub issues | `./scripts/sync_to_github.sh` |
| `reset_github_progress.sh` | Reset GitHub issues | `./scripts/reset_github_progress.sh` |
| `progress_tracker.html` | Visual progress tracker | Open in browser |

## 📈 Best Practices

### 1. Preparation Cycle Workflow
1. **Start**: Run `./scripts/reset_progress.sh`
2. **Sync**: Run `./scripts/sync_to_github.sh` to create GitHub issues
3. **Study**: Work through problems systematically using GitHub Projects
4. **Track**: Drag issues between columns (To Do → In Progress → Done)
5. **Review**: Use GitHub Projects UI for progress visualization

### 2. Tracking Progress in GitHub Projects
- ✅ **Done Column**: Problem solved and understood
- ⏭️ **Skipped Column**: Too difficult, revisit later
- 🔄 **In Progress Column**: Currently working on
- 📋 **To Do Column**: Haven't attempted yet

### 3. Study Recommendations
- Start with **Beginner** level problems
- Complete at least 70% of each level before moving up
- Don't skip too many problems - aim for understanding
- Use the HTML tracker for visual motivation

## 🎨 Customization

### Adding New Topics
1. Create a new README in the appropriate directory
2. Add checkboxes using the format: `- [ ] **Problem Name**`
3. Update the main README to include the new topic
4. Add the topic to the reset script if needed

### Adding New Problems
1. Add to the appropriate topic README
2. Use the standard checkbox format
3. Update progress counters manually or via script

## 🚨 Troubleshooting

### Checkboxes Not Working
- Ensure you're using the correct format: `- [ ]` or `- [x]`
- Check that there are no extra spaces
- Verify the markdown syntax is correct

### Scripts Not Running
- Make sure scripts are executable: `chmod +x scripts/*.sh`
- Run from the repository root directory
- Check that you have bash installed

### Progress Not Updating
- Manually update progress counters in README files
- Run the reset script to refresh all counters
- Check that the script paths are correct

## 💡 Tips for Success

1. **Set Daily Goals**: Aim for 2-3 problems per day
2. **Track Consistently**: Update checkboxes immediately after solving
3. **Review Regularly**: Use progress reports to stay motivated
4. **Don't Rush**: Focus on understanding, not just completion
5. **Take Breaks**: Use the system to plan study sessions

## 🔄 Reset and Restart

When starting a new preparation cycle:
1. Run `./scripts/reset_progress.sh`
2. This clears all checkboxes and resets counters
3. You can start fresh with a clean slate
4. Perfect for different interview rounds or job applications

---

**Happy Coding! 🚀** Use this system to stay organized and motivated during your preparation journey.
