class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;
        string s1;
        string s2;
        vector<int> freq1;
        vector<int> freq2;
        for(auto c : word1)
            ++count1[c];
        for(auto c: word2)
            ++count2[c];
        for(const auto &[c,freq] : count1){
            s1 += c;
            freq1.push_back(freq);
        }
        for(const auto &[c,freq] : count2){
            s2 += c;
            freq2.push_back(freq);
        }
        sort(begin(s1),end(s1));
        sort(begin(s2),end(s2));
        
        if(s1 != s2)
            return false;
        
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));
        
        return freq1 == freq2;
    }
};
