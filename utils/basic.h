#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <vector>

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

    namespace mymath{
        int get_max(std::vector<int> &input){
            int max = INT32_MIN;
            for(int i=0; i<input.size(); i++){
                if(input[i]>max){
                    max = input[i];
                }
            }

            return max;
        }
    }
}

#endif // UTILS_H_INCLUDED