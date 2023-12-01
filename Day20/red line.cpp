#include <iostream>
using namespace std;
 
int main() {
	int t; cin>>t;
	while(t--){
		int n,x; cin>>n>>x; 
		int a=0;
		int ans=0;
		while(n--){
			int b; cin>>b;
			ans=max(ans, b-a);
			a=b;
		}
		cout<<max(ans, 2*(x-a))<<endl;
	}
}
