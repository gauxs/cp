#include <vector>
#include <iostream>

#include "utils/basic.h"

#ifndef MERGE_LINKEDLIST_H_INCLUDED
#define MERGE_LINKEDLIST_H_INCLUDED

void print_linked_list(struct node* root){
    while(root!=NULL){
        std::cout<<root->data<<" ";
        root=root->next;
    }
    std::cout<<endl;
    return;
}

struct node* divide_linked_list(struct node* root){
    struct node* slow=root;
    struct node* fast=root->next;
    struct node* mid=NULL;
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

struct node* merge_linked_list(struct node* left, struct node* right){
    struct node* root=NULL;
    struct node* prev_root=NULL;
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

struct node* merge_sort_linked_list(struct node* root){
    if(root==NULL || root->next==NULL){
        return root;
    }else{
        struct node* mid=NULL;
        mid=divide_linked_list(root);
        //std::cout<<"Mid at ele: "<<mid->data<<endl;
        root=merge_sort_linked_list(root);
        mid=merge_sort_linked_list(mid);

        root=merge_linked_list(root, mid);
        //print_linked_list(root);
        return root;
    }
}

#endif // MERGE_LINKEDLIST_H_INCLUDED
