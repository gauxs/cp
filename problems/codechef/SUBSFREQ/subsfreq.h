#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

#ifndef SUBSFREQ_H_INCLUDED
#define SUBSFREQ_H_INCLUDED

using namespace std;

void initialize(vector<vector<int> > &mem, int n){
    for(int i=0; i<n; i++){
        mem[i][0] = 1;
        mem[i][n-1] = 1;
    }
    return;
}

void print(vector<vector<int> > &mem, int n){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void solve(vector<int> &input, int n, vector<vector<int> > &mem){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(input[j]>=i){
                if(input[j-1]>=i){
                    mem[i][j] = mem[i][j-1] * i;
                }else{
                    mem[i][j] = mem[i][j-1] * (input[j-1]+1);
                }
            }else{
                mem[i][j] = mem[i][j-1];
            }
        }
    }
    print(mem, n+2);
    for(int i=1; i<=n; i++){
        for(int j=n; j>=1; j--){
            if(input[j]>=i){
                //mem[i][j]--;
                if(input[j+1]>=i){
                    mem[i][j] *= (mem[i][j+1] * (i+1));
                }else{
                    mem[i][j] *= (mem[i][j+1] * (input[j+1]+1));
                }
            }else{
                mem[i][j] = mem[i][j+1];
            }
        }
    }

    int temp=0;
    for(int j=1; j<=n; j++){
        if(input[j]!=0){
            for(int i=1; i<=input[j]; i++){
                temp = (temp + mem[i][j]) % 1000000007;
            }
            cout<<temp<<" ";
            temp=0;
        }else{
            cout<<"0"<<" ";
        }
    }
    cout<<endl;
    return;
}



int subsfreq(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, temp;
        cin>>n;
        vector<int> input(n+2);
        vector<vector<int> > mem(n+2, vector<int>(n+2));
        for(int i=0; i<n; i++){
            cin>>temp;
            input[temp]++;
        }
        initialize(mem, n+2);
        solve(input, n, mem);
        print(mem, n+2);
    }

    return 0;
}

#endif // SUBSFREQ_H_INCLUDED
