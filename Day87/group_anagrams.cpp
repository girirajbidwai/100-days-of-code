class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> mp;

        for(int i = 0; i < strs.size(); i++){
            vector<int> tmp(26,0);
            for(int j = 0; j < strs[i].size(); j++){
                tmp[strs[i][j] - 'a']++;
            }
            mp[tmp].push_back(strs[i]);
        }
        for(auto &it : mp){
            vector<string> tmp;
            for(auto &it1 : it.second){
                tmp.push_back(it1);
            }
            ans.push_back(it.second);
        }
        return ans;
    }
};
