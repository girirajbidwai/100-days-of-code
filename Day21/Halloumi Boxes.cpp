#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
 
 ll n,k;
cin>>n;
while(cin>>n>>k)
{
   ll a[n];
   ll x=1;
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=1;i<n ;i++)if(a[i]<a[i-1])x=0;
   puts(k==1 &&x==0?"NO":"YES");

}



}
