class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> vis(n,0);
        vector<int> in(n,0);
        vector<int> adj[n+1];
        for(int i = 0; i < p.size(); i++){
            in[p[i][0]]++;
            adj[p[i][1]].push_back(p[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(in[i] == 0) {
                vis[i] = 1;
                q.push(i);
            }
        }
        
       // cout<<vis[0]<<vis[1];
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto &it : adj[top]){
                in[it]--;
                if(in[it] == 0) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};
