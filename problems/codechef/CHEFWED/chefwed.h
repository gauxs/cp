#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

#ifndef CHEFWED_H_INCLUDED
#define CHEFWED_H_INCLUDED

using namespace std;

int solve(int n, int k, vector<int> &families, int cur_person, vector<int> &mem){
    if(cur_person>=n){
        return INT_MAX;
    }

    if(mem[cur_person]!=-1)
        return mem[cur_person];

    vector<int> families_mapping(101);
    int total_inneficiency=INT_MAX, current_inefficiency=0, least_inefficiency=INT_MAX, returned_inefficiency=INT_MAX;
    for(int i=cur_person; i<n; i++){
        families_mapping[families[i]]++;
        if(families_mapping[families[i]]>=2){
            if(families_mapping[families[i]]==2){
                current_inefficiency+=2;
            }else{
                current_inefficiency++;
            }
        }

        returned_inefficiency = solve(n, k, families, i+1, mem);
        if(returned_inefficiency!=INT_MAX){
            returned_inefficiency+= current_inefficiency + k;
        }
        if(returned_inefficiency<least_inefficiency){
            least_inefficiency = returned_inefficiency;
        }
    }
    total_inneficiency = current_inefficiency + k;
    mem[cur_person] = min(least_inefficiency, total_inneficiency);
    return mem[cur_person];
}

int chefwed(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int> families(n);
        vector<int> mem(n, -1);
        for(int i=0; i<n; i++){
            cin>>families[i];
        }

        cout<<solve(n, k, families, 0, mem)<<endl;
    }

    return 0;
}

#endif // CHEFWED_H_INCLUDED
