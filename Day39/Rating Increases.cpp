#include<bits/stdc++.h>
using namespace std;
int t,a,b;
string c;
int main(){
	scanf("%d",&t);
	while(t--){
		a=b=0;cin>>c;
		a=c[0]-'0';
		int i=1;
		for(;i<c.length();i++){
			if(c[i]=='0')a*=10;
			else break;
		}
		for(;i<c.length();i++)b=b*10+(c[i]-'0');
		if(b>a)cout<<a<<" "<<b<<endl;
		else cout<<-1<<endl;
	}
}
