class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m){
                if(s[j] >= g[i]){
                    ans++;
                    j++;
                    break;
                }
                else j++;
            }
        }
        return ans;
    }
};
