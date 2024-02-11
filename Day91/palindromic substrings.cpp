class Solution {
    int solve(vector<vector<int>> &dp, string &s, int i, int j){
        // While recurring checks, if i >= j then return 1 to say that palindrom checks are over for the given substring
        if(i >= j)
            return 1;
        // If we already have data for a specific substring, return it.
        if(dp[i][j] >= 0)
            return dp[i][j];
        // Check if current first and last char of current substring is palindrome,
        // if they are equal then check for second and second-last char by making a recursive call.
        // if first & last char are not equal, then store 0 in dp[i][j] to say that it's not palindrome, then finally return dp[i][j]
        if(s[i] == s[j])
            dp[i][j] = solve(dp, s, i+1, j-1);
        else
            dp[i][j] = 0;
        return dp[i][j];
    }
public:
    int countSubstrings(string s) {
        int N = s.length();
        // create a  N*N vector of -1 default value. This dp array would store data whether our substring from ith to jth char is palindrome or not.
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int count = 0;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                count += solve(dp, s, i, j);
            }
        }
        return count;
    }
};
