#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>>arr(n, vector<int>(n,0));
        vector<int>ans(n,((1<<30)-1));
        bool f=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                if(i!=j)ans[i]&=arr[i][j];
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && (ans[i]|ans[j])!=arr[i][j]){
                    f=true;
                    break;
                }
            }
        }
        if(f)cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(int x:ans)cout<<x<<" ";
            cout<<endl;
        }
    }
}
