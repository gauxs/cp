# 🎯 GitHub Projects Setup Guide

This guide shows how to set up GitHub Projects for tracking your competitive programming preparation progress.

## 🚀 **Step 1: Install GitHub CLI**

```bash
# macOS
brew install gh

# Or download from: https://cli.github.com/
```

## 🔐 **Step 2: Authenticate with GitHub**

```bash
gh auth login
# Follow the prompts to authenticate
```

## 📋 **Step 3: Create Issues from Markdown**

```bash
# Run the sync script to create GitHub issues
./scripts/sync_to_github.sh
```

This will:
- ✅ Scan your markdown files for unchecked problems
- ✅ Create GitHub issues for each problem
- ✅ Add appropriate labels (beginner, intermediate, advanced)
- ✅ Assign issues to you

## 🎯 **Step 4: Create GitHub Project**

1. **Go to your repository** on GitHub
2. **Click "Projects"** tab
3. **Click "New project"**
4. **Choose "Table" view**
5. **Name it**: "CP Preparation Progress"

## 📊 **Step 5: Set Up Project Columns**

Create these columns in order:
- **To Do** (Backlog)
- **In Progress** (Currently working on)
- **Done** (Completed)
- **Skipped** (Too difficult, revisit later)

## 🏷️ **Step 6: Add Issues to Project**

1. **Go to your project**
2. **Click "+" to add items**
3. **Select "Issues"**
4. **Add all the issues** created by the sync script
5. **Organize by difficulty** using labels

## 🔄 **Step 7: Workflow for Daily Use**

### **Starting a New Problem:**
1. Find the issue in "To Do" column
2. Drag it to "In Progress"
3. Add a comment with your approach
4. Link to your solution code

### **Completing a Problem:**
1. Drag from "In Progress" to "Done"
2. Add a comment with solution summary
3. Link to your implementation

### **Skipping a Problem:**
1. Drag to "Skipped" column
2. Add a comment explaining why
3. Set a reminder to revisit later

## 📈 **Step 8: Track Progress**

### **Visual Progress:**
- **Project dashboard** shows completion charts
- **Burndown charts** track daily progress
- **Filter by labels** to see difficulty breakdown

### **Progress Tracking:**
```bash
# Reset all progress for new cycle
./scripts/reset_progress.sh

# Sync to GitHub Projects for visual tracking
./scripts/sync_to_github.sh
```

## 🔄 **Step 9: Reset for New Preparation Cycle**

### **Option A: Archive Current Project**
1. Go to project settings
2. Click "Archive project"
3. Create new project with same structure
4. Re-run sync script

### **Option B: Reset Issues**
1. Move all "Done" issues to "To Do"
2. Clear all comments
3. Update labels if needed

## 🎨 **Step 10: Customize Your Project**

### **Add Custom Fields:**
- **Time Spent** (number field)
- **Difficulty Rating** (single select)
- **Solution Language** (single select)
- **Notes** (text field)

### **Create Views:**
- **By Difficulty**: Filter by beginner/intermediate/advanced
- **By Topic**: Filter by sorting/search/graph
- **This Week**: Filter by due dates
- **Stuck**: Filter by issues in progress > 3 days

## 📱 **Step 11: Mobile Access**

- **GitHub Mobile App**: View and update issues on the go
- **Mobile Web**: Full project board access
- **Notifications**: Get updates on issue changes

## 🔧 **Advanced Features**

### **Automation Rules:**
- Auto-move issues to "In Progress" when assigned
- Auto-move to "Done" when PR is merged
- Auto-assign based on labels

### **Integration:**
- **VS Code**: GitHub Pull Requests extension
- **Slack**: GitHub integration for notifications
- **Calendar**: Sync with study schedule

## 💡 **Pro Tips**

1. **Use Milestones**: Create weekly/monthly milestones
2. **Add Due Dates**: Set realistic deadlines
3. **Use Comments**: Document your thought process
4. **Link Code**: Always link to your solution
5. **Review Regularly**: Weekly progress reviews
6. **Celebrate Wins**: Mark major achievements

## 🚨 **Troubleshooting**

### **Issues Not Syncing:**
```bash
# Check GitHub CLI status
gh auth status

# Re-authenticate if needed
gh auth login
```

### **Project Not Loading:**
- Check repository permissions
- Ensure you're a collaborator
- Try refreshing the page

### **Issues Not Appearing:**
- Check if issues were created successfully
- Verify repository name in sync script
- Check GitHub API rate limits

---

**🎉 You're all set!** Your GitHub Project will now provide a visual, interactive way to track your competitive programming preparation progress.
