#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T,n,p,t,l; string s; cin>>T;
    while(T--&&cin>>n>>p>>l>>t){
        int task((n+6)/7),c(max((p-1)/(2*t+l)+1,(p-t*task-1)/l+1));
        cout<<n-c<<'\n';
    }
}
