#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // O(logN)
    ListNode *findMid(ListNode *left, ListNode *right)
    {
        ListNode *slow = left;
        ListNode *fast = left;
        while (fast != right && fast->next != right)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    int findLen(ListNode *left, ListNode *right)
    {
        if (left == NULL)
        {
            return 0;
        }

        int len = 1;
        while (left != right)
        {
            len++;
            left = left->next;
        }

        return len;
    }

    ListNode *mergeArray(ListNode *leftList, ListNode *rightList)
    {
        ListNode *dummyNode = new ListNode();
        ListNode *tail = dummyNode;
        while (leftList != NULL && rightList != NULL)
        {
            if (leftList->val < rightList->val)
            {
                tail->next = leftList;
                leftList = leftList->next;
            }
            else
            {
                tail->next = rightList;
                rightList = rightList->next;
            }
            tail = tail->next;
        }

        tail->next = leftList != NULL ? leftList : rightList;
        return dummyNode->next;
    }

    ListNode *mergeSort(ListNode *left, ListNode *right)
    {
        if (left == right)
        {
            left->next = NULL;
            return left;
        }

        ListNode *mid = findMid(left, right);
        ListNode *midNext = mid->next;
        mid->next = nullptr;
        ListNode *leftMerge = mergeSort(left, mid);
        ListNode *rightMerge = mergeSort(midNext, right);

        return mergeArray(leftMerge, rightMerge);
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *end = head;
        while (end->next != NULL)
        {
            end = end->next;
        }

        return mergeSort(head, end);
    }
};

#endif // MERGE_H_INCLUDED