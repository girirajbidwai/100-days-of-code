#include<bits/stdc++.h>
using namespace std;
void solve(){
    //int a,b,c;
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0] == a[1]) cout<<a[2]<<endl;
    else cout<<a[0]<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
