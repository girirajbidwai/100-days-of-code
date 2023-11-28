#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	vector<int> ans;
	for(int i = 0; i <= m; i++){
		ans.push_back(arr[i]);	
	}
	int n = arr.size()-1;
	for(int i = n;i > m; i--){
		ans.push_back(arr[i]);
	}
	arr = ans;
	// for(int i : ans) cout<<i<<" ";
}
