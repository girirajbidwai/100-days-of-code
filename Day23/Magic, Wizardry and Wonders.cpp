#include<iostream>
using namespace std;
int main()
{
int n,k,m,a[105],i;
cin>>n>>k>>m;
for(i=1;i<=n;i++)
{
if(k>0) a[i]=m;
else a[i]=1;
k=a[i]-k;
}
a[n]-=k;
if(a[n]<=0 || a[n]>m) cout<<-1;
else
{
for(i=1;i<=n;i++) cout<<a[i]<<" ";
}
return 0;
}
