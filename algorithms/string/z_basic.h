#ifndef Z_BASIC_H_INCLUDED
#define Z_BASIC_H_INCLUDED

#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fill_z_arr(string &s, vector<int> &z_arr){
    int str_len=s.length();
    int l_zbox=0, r_zbox=0, prefix_pos=0;

    for(int i=0; i<str_len; i++){
        if(i>r_zbox){
            l_zbox=r_zbox=i;
            while(r_zbox<str_len && s[r_zbox-l_zbox]==s[r_zbox]){
                r_zbox++;
            }
            z_arr[i]=r_zbox-l_zbox;
            r_zbox--;
        }else{
            prefix_pos=i-l_zbox;
            if(z_arr[prefix_pos]<r_zbox-i+1){
                z_arr[i]=z_arr[prefix_pos];
            }else{
                l_zbox=i;
                while(r_zbox<str_len && s[r_zbox-l_zbox]==s[r_zbox]){
                    r_zbox++;
                }
                z_arr[i]=r_zbox-l_zbox;
                r_zbox--;
            }
        }
    }
    return;
}

//int main(){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    string pat, s;
//    cin>>pat;
//    cin>>s;
//
//    string new_string = pat+"$"+s;
//    vector<int> z_arr(new_string.length());
//
//    fill_z_arr(new_string, z_arr);
//
//    int pat_len=pat.length(), count=0;
//    for(int i=0; i<new_string.length(); i++){
//        if(z_arr[i]==pat_len){
//            count++;
//        }
//    }
//    cout<<count<<endl;
//
//    return 0;
//}

#endif // Z_BASIC_H_INCLUDED
