#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	set<int> s[n+1];
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		s[x].insert(y);
		s[y].insert(x);
	}
	for(int i = 1; i <= n; i++) s[i].insert(i);
	vector<int> vis(n+1, 0);
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i]++;
			for(int j : s[i]) {
				vis[j]++;
				if(s[i] != s[j]) {
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES";
}
