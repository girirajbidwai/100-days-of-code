class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        vector<vector<int>> ans;
        int maxi = INT_MIN;
        for(int i : nums){
            mp[i]++;
            maxi = max(mp[i],maxi);
        }
        
        for(int i = 0; i < maxi; i++){
            vector<int> vec;
            
            for(auto it : mp){
                if(it.second){
                    vec.push_back(it.first);
                    mp[it.first]--;
                }
                // if(it.second == 0) mp.erase(it.first);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
