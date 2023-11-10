#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    if(y <= x){
        cout<<x<<endl;
        return;
    }
    else{
        if((y - x) <= k){
            cout<<y<<endl;
            return;
        }
        else{
            int tmp = x + k;
            cout<<2*(y-tmp)+tmp<<endl;
            return;
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
