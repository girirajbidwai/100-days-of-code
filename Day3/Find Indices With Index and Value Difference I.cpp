class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int ind, int val) {
        // vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(abs(i-j) >= ind){
                    if(abs(nums[i]-nums[j] >= val)) return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
