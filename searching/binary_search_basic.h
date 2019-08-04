#ifndef BINARY_SEARCH_BASIC_H_INCLUDED
#define BINARY_SEARCH_BASIC_H_INCLUDED

int binary_basic_search(std::vector<int> &arr, int low, int high, int ele){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==ele){
            return mid;
        }else if(arr[mid]<ele){
            low=mid-1;
        }else{
            high=mid+1;
        }
    }
    return -1;
}

#endif // BINARY_SEARCH_BASIC_H_INCLUDED
