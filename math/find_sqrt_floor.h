#ifndef FIND_SQRT_FLOOR_H_INCLUDED
#define FIND_SQRT_FLOOR_H_INCLUDED

long long int binary_search1(long long int ele, long long int low, long long int high){
    if(low<high){
        long long int cur=(low+high)/2+1;
        //cout<<"Mid: "<<cur<<endl;
        long long int t=cur*cur;
        if(t==ele){
            return cur;
        }else if(t>ele){
            return binary_search1(ele, low, cur-1);
        }else{
            return binary_search1(ele, cur, high);
        }
    }
    return low;
}

long long int floorSqrt(long long int x) {
    return binary_search1(x, 0, x);
}

#endif // FIND_SQRT_FLOOR_H_INCLUDED
