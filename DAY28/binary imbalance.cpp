#include<bits/stdc++.h>
    using namespace std;
 
    void solve(){
        int n;
        string s;
        cin>>n>>s;
        int ones=0,zeroes=0;
        int flag=0;
        for(auto &it : s){
            if(it == '0') zeroes++;
            else ones++;
        }
 
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]) flag = 1;
        }
 
        if(flag) cout<<"YES\n";
        else if(zeroes > ones) cout<<"YES\n";
        else cout<<"NO\n";
 
        return;
    }
    int main(){
        int t;
        cin>>t;
        while(t--){
            solve();
        }
        
    }
