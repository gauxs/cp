#ifndef MERGE_SORT_LINKEDLIST_H_INCLUDED
#define MERGE_SORT_LINKEDLIST_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

struct Node{
    int data;
    Node* next;
};

void print_linked_list(Node* root){
    while(root!=NULL){
        std::cout<<root->data<<" ";
        root=root->next;
    }
    std::cout<<std::endl;

    return;
}

struct Node* divide_linked_list(Node* root){
    Node* slow=root;
    Node* fast=root->next;
    Node* mid=NULL;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    mid=slow->next;
    slow->next=NULL;

    return mid;
}

Node* merge_linked_list(Node* left, Node* right){
    Node* root=NULL;
    Node* prev_root=NULL;

    if(left->data<=right->data){
        root=left;
        left=left->next;
    }else{
        root=right;
        right=right->next;
    }

    root->next=NULL;
    prev_root=root;
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
            prev_root->next=left;
            prev_root=left;
            left=left->next;
            prev_root->next=NULL;
        }else{
            prev_root->next=right;
            prev_root=right;
            right=right->next;
            prev_root->next=NULL;
        }
    }

    while(left!=NULL){
        prev_root->next=left;
        prev_root=left;
        left=left->next;
        prev_root->next=NULL;
    }

    while(right!=NULL){
        prev_root->next=right;
        prev_root=right;
        right=right->next;
        prev_root->next=NULL;
    }

    return root;
}

Node* merge_sort_linked_list(Node* root){
    if(root==NULL || root->next==NULL){
        return root;
    }else{
        Node* mid = divide_linked_list(root);
        root = merge_sort_linked_list(root);
        mid = merge_sort_linked_list(mid);
        root = merge_linked_list(root, mid);
        return root;
    }
}

#endif // MERGE_SORT_LINKEDLIST_H_INCLUDED
