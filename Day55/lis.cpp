class Solution {
public:
    int f(int i,int prev,vector<vector<int>> &dp,vector<int> &nums){
        if(i == nums.size()){
            return 0;
        }
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int npick = f(i+1,prev,dp,nums);
         
        int pick = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            pick += f(i+1,i,dp,nums);
            pick += 1;
        }
        return dp[i][prev+1] = max(npick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size()+5,-1));
        return f(0,-1,dp,nums);
    }
};
