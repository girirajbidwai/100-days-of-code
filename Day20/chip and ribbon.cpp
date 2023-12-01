#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
int t; cin>>t;
while(t--){
ll n; cin>>n;
vector<ll> v(n);
for(ll i=0;i<n;i++) cin>>v[i];
ll ans=0,last=0;
for(ll i=0;i<n;i++) {
 if(v[i]>last) ans+=v[i]-last;
 last=v[i];
}
cout<<ans-1<<endl;
}
 
return 0;
}
