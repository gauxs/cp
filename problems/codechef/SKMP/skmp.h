#include <iostream>
#include <vector>

#ifndef SKMP_H_INCLUDED
#define SKMP_H_INCLUDED

using namespace std;

int skmp(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, len_s, len_p;
    cin>>t;

    while(t--){
        string str, p;
        cin>>str;
        cin>>p;

        len_s = str.length();
        len_p = p.length();

        vector<int> s_freq(26);

        for(int i=0; i<len_s; i++){
            s_freq[str[i]-'a']++;
        }
        for(int i=0; i<len_p; i++){
            s_freq[p[i]-'a']--;
        }

        bool left = false;
        int temp = s_freq[p[0]-'a'];
        int tempInd = 1;
        while(temp!=0 && len_p>1){
            if(p[tempInd]-'a' < (p[0]-'a')){
                left = false;
                break;
            }else if(p[tempInd]-'a' > (p[0]-'a')){
                left = true;
                break;
            }
            tempInd++;
            temp--;
        }

        int str_ind=0;
        if(left){
            for(int i=0; i<=(p[0]-'a'); i++){
                while(s_freq[i]){
                    str[str_ind] = (char)(i+'a');
                    str_ind++;
                    s_freq[i]--;
                }
            }

            for(int i=0; i<len_p; i++){
                str[str_ind] = p[i];
                str_ind++;
            }

            for(int i=(p[0]-'a')+1; i<26; i++){
                while(s_freq[i]){
                    str[str_ind] = (char)(i+'a');
                    str_ind++;
                    s_freq[i]--;
                }
            }
        }else{
            for(int i=0; i<(p[0]-'a'); i++){
                while(s_freq[i]){
                    str[str_ind] = (char)(i+'a');
                    str_ind++;
                    s_freq[i]--;
                }
            }

            for(int i=0; i<len_p; i++){
                str[str_ind] = p[i];
                str_ind++;
            }

            for(int i=(p[0]-'a'); i<26; i++){
                while(s_freq[i]){
                    str[str_ind] = (char)(i+'a');
                    str_ind++;
                    s_freq[i]--;
                }
            }
        }

        cout<<str<<endl;
    }
    return 0;
}

#endif // SKMP_H_INCLUDED
