class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& vec, int k) {
        sort(vec.begin(),vec.end());
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i = 0; i < vec.size(); i+=3){
            if(vec[i+2] - vec[i] > k) return {};
            else{
                tmp.clear();
                tmp.push_back(vec[i]);
                tmp.push_back(vec[i+1]);
                tmp.push_back(vec[i+2]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
