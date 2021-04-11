#include <vector>

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

namespace myutils{
    namespace myswap{
        void swap(int* a, int* b){
            int temp=*a;
            *a=*b;
            *b=temp;
        }

        void swap(int& a, int& b){
            int temp=a;
            a=b;
            b=temp;
        }
    }

    namespace myprint{
        void print(std::vector<int>& vec, int len){
            for(int i=0; i<len; i++){
                std::cout<<vec[i]<<" ";
            }
            std::cout<<std::endl;
            
            return;
        }
    }
}

#endif // UTILS_H_INCLUDED