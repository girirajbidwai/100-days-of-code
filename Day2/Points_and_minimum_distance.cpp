
#include <bits/stdc++.h>
using namespace std;
int t,n,a[310];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++) cin>>a[i];
		sort(a+1,a+1+2*n);
		cout<<a[n]-a[1]+a[2*n]-a[n+1]<<'\n';
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' '<<a[i+n]<<'\n';
	}
}
