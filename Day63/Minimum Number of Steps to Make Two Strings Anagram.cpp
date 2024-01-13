class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26,0);
        
        for(int i = 0; i < s.size(); i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        
        int ans = 0;
        for(int i : v){
            ans += abs(i);
        }
        return ans/2;
    }
};
