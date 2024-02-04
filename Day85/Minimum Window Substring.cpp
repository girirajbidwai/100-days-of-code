class Solution{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char,int> mp;
        int count = t.size();
        for(auto c: t)
            mp[c]++;
        
        int size = __INT_MAX__;
        int j = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]--;
            if(mp[s[i]] >= 0){
                count--;
            }

            if(count == 0)
            {
                while(j <= i && mp[s[j]] < 0)
                {
                    mp[s[j]]++;
                    j++;
                }
                if(i-j+1 < size)
                {
                    size = i-j+1;
                    ans = s.substr(j,size);
                }
            }
        }

        
        return ans;
    }
};
