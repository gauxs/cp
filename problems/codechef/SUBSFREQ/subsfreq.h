#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

#ifndef SUBSFREQ_H_INCLUDED
#define SUBSFREQ_H_INCLUDED

using namespace std;

int subsfreq(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> input(n);
        for(int i=0; i<n; i++){
            cin>>input[i];
        }

        std::sort(input.begin(), input.end());

        cout<<""<<endl;
    }

    return 0;
}

#endif // SUBSFREQ_H_INCLUDED
