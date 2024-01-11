const ll INF = 1e18;
void Solve() {
	int n,x,z;
	cin >> n >> x >> z;
	vector<int>a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll>dp(x,INF);
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		vector<ll>tmp = dp;
		for(int j = 0; j < x; j++) {
			tmp[(j + a[i]) % x] = min(tmp[(j + a[i]) % x],dp[j] + a[i]);
		}
		dp = tmp;
	}
	ll ans = dp[(x - z % x) % x];
	cout << (ans == INF ? -1 : (ans + z) / x) << nl;
}	
int main() {
	fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
	int tt;
	cin >> tt;
	while(tt--) {
		Solve(); 
	}
    return 0;
}
