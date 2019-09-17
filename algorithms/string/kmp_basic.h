#ifndef KMP_BASIC_H_INCLUDED
#define KMP_BASIC_H_INCLUDED

void fill_kmp_arr(string &pat, vector<int> &lps_arr){
    int lps_len=0, pos=0;
    int pat_len=pat.length();

    // lps_arr[i]-length of longest lps in lps_arr[0...i]
    for(int i=1; i<pat_len; i++){
        if(pat[lps_len]==pat[i]){
            lps_len++;
            lps_arr[i]=lps_len;
        }else{
            while(lps_len>0){
                lps_len=lps_arr[lps_len-1];
                if(pat[lps_len]==pat[i]){
                    lps_len++;
                    lps_arr[i]=lps_len;
                    break;
                }
            }
        }
    }

    return;
}

//int main(){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    string p, s;
//    cin>>p>>s;
//
//    vector<int> lps_arr(p.length());
//    fill_kmp_arr(p, lps_arr);
//
//    for(int i=0; i<p.length(); i++){
//        cout<<lps_arr[i]<<" ";
//    }
//    cout<<endl;
//
//    int i=0, pat_pos=0, count=0;
//    while(i<s.length()){
//        if(p[pat_pos]==s[i]){
//            i++;
//            pat_pos++;
//        }
//        if(pat_pos==(p.length())){
//            count++;
//            pat_pos=lps_arr[pat_pos-1];
//        }else if(i<s.length() && p[pat_pos]!=s[i]){
//            if(pat_pos!=0){
//                pat_pos=lps_arr[pat_pos-1];
//            }else{
//                i++;
//            }
//        }
//    }
//
//    cout<<count<<endl;
//    return 0;
//}

#endif // KMP_BASIC_H_INCLUDED
