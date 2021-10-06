#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

#include<algorithm>

/*
    AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right 
    subtrees cannot be more than one for all nodes. 

    Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST.
    The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that height of the tree remains O(Logn)
    after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an
    AVL tree is always O(Logn) where n is the number of nodes in the tree.

    Comparison with Red Black Tree 
        The AVL tree and other self-balancing search trees like Red Black are useful to get all basic operations done in O(log n) time. 
        The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. 
        So if your application involves many frequent insertions and deletions, then Red Black trees should be preferred. And if the insertions
        and deletions are less frequent and search is the more frequent operation, then AVL tree should be preferred over Red Black Tree.

    Are duplicate keys allowed in the definition of binary search trees?
        If your binary search tree is a red black tree, or you intend to any kind of "tree rotation" operations, duplicate nodes will cause problems.
        Imagine your tree rule is this:
                left < root <= right
        Now imagine a simple tree whose root is 5, left child is nil, and right child is 5. If you do a left rotation on the root you end up with a 5
        in the left child and a 5 in the root with the right child being nil. Now something in the left tree is equal to the root, but your rule above
        assumed left < root.
        Reference: https://stackoverflow.com/a/339597

    Reference:  
    1 - https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
    2 - https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
*/

/*
    Time Complexity: 
    The rotation operations (left and right rotate) take constant time as only a few pointers are being changed there. Updating the 
    height and getting the balance factor also takes constant time. So the time complexity of AVL insert remains same as BST insert which is O(h)
    where h is the height of the tree. Since AVL tree is balanced, the height is O(Logn). So time complexity of AVL insert is O(Logn).
*/
struct AVLTreeNode{
    int val;
    int height;
    AVLTreeNode* left;
    AVLTreeNode* right;
};

AVLTreeNode* newNode(int v){
    AVLTreeNode node;
    node.val = v;
    node.height = 0;
    node.left = nullptr;
    node.right = nullptr;
    return &node;
}

int height(AVLTreeNode* node){
    if(node==nullptr)
        return 0;
    
    return node->height;
}

int getBalance(AVLTreeNode* node){
    if(node==nullptr)
        return 0;
    
    return height(node->left) - height(node->right);
}

AVLTreeNode* leftRotate(AVLTreeNode* root){
    AVLTreeNode* root_right = root->right;
    AVLTreeNode* root_right_left = root->right->left;

    root->right = root_right_left;
    root_right->left = root;

    // first do for "root" since it is now the lower node
    root->height = 1 + std::max(height(root->left), height(root->right));
    root_right->height = 1 + std::max(height(root->left), height(root->right));

    return root_right;
}

AVLTreeNode* rightRotate(AVLTreeNode* root){
    AVLTreeNode* root_left = root->left;
    AVLTreeNode* root_left_right = root->left->right;

    root->left = root_left_right;
    root_left->right = root;

    // first do for "root" since it is now the lower node
    root->height = 1 + std::max(height(root->left), height(root->right));
    root_left->height = 1 + std::max(height(root_left->left), height(root_left->right));

    return root_left;
}

AVLTreeNode* insert(AVLTreeNode* root, int key){
    if(root==nullptr)
        return newNode(key);
    
    if(key<root->val)
        root->left = insert(root->left, key);
    else if(key>root->val)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + std::max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Left-Left case
    if(balance>1 && (key<root->left->val))
        return rightRotate(root);

    // Left-Right case
    if(balance>1 && (key>root->left->val)){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Right case
    if(balance<-1 && (key>root->right->val))
        return leftRotate(root);

    // Right-Left case
    if(balance<-1 && (key<root->right->val)){
        rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

#endif // AVL_TREE_H_INCLUDED