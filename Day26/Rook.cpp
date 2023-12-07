#include<bits/stdc++.h>
using namespace std;

void solve(){
    string st;
    cin>>st;

    vector<int> a(8,0);
    vector<int> b(8,0);

    a[st[0]-'a'] = 1;
    b[st[1]-'0'-1] = 1;

    // string ch1 = st[0];
    for(int i = 0; i < 8; i++){
        if(!b[i]){
            cout<<st[0]<<to_string(i+1)<<" ";
        }
    }
    // string ch2 = st[1];
    for(int i = 1; i <= 8; i++){
        if(!a[i-1]){
            cout<<char('a' + (i-1))<<st[1]<<" ";
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
