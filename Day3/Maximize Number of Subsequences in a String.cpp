class Solution {

public:

    long long solve(int i,int j,string &s,string &t, vector<vector<long long>> &dp){

        if(j==0) return 1;

        if(i<0) return 0;

        

        if(dp[i][j]!=-1) return dp[i][j];

        

        long long tk=0;

        if(s[i]==t[j-1]) tk = solve(i-1,j-1,s,t,dp);

        long long nottk = solve(i-1,j,s,t,dp);

        

        return dp[i][j] = tk+nottk;

    }

    long long maximumSubsequenceCount(string s, string t) {

        int n = s.size()+1;

        int ct0=0,ct1=0;

        vector<vector<long long>> dp(n+1,vector<long long>(3,-1));

        for(int i=0;i<n-1;i++){

            if(s[i]==t[0]) ct0++;

            else if(s[i]==t[1]) ct1++;

        }

        

        long long ans=0;

        if(ct1<=ct0){

            s.push_back(t[1]);

            ans = max(ans,solve(n-1,2,s,t,dp));

        }

        else{

            string ch;

            ch += t[0];

            s.insert(0,ch);

            ans = max(ans,solve(n-1,2,s,t,dp));

        }

        

        return ans;

    }

};

