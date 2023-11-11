#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int>a(n);
	for(int i=0; i<n; i++) cin >> a[i];
    int f = 1;
	for(int i=1; i<n; i++)
		if(a[i] < a[i-1])
			if((i & i-1))
				f = 0;
 
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}
