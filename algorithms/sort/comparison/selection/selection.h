#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "utils/basic.h"

void selection_sort(
    std::vector<int> &arr,
    int n)
{

    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }

    return;
}

#endif // SELECTION_H_INCLUDED