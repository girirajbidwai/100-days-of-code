#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int l[n+1],r[n+1];
		for(int i=1;i<=n;i++){
			cin>>l[i]>>r[i];
		}
		int a=0,b=1e9;
		while(a<=b){
			int mid=a+b>>1;
			int u=0,v=0,flag=0;
			for(int i=1;i<=n;i++){
				u=max(l[i],u-mid);
				v=min(r[i],v+mid);
				if(u>v) flag=1;
			}
			if(flag==0) b=mid-1;
			else a=mid+1;
		}
		cout<<a<<endl;
	}
	return 0;
}
