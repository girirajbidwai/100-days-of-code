class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> vec(grid.size()*grid.size()+1,0);
        
        for(int i = 0;i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                vec[grid[i][j]]++;
            }
        }
        vector<int> res(2);
        for(int i = 1; i < vec.size(); i++){
            if(vec[i] > 1) res[0] = i;
            else if(vec[i] == 0) res[1] = i;
        }
        return res;
    }
};
