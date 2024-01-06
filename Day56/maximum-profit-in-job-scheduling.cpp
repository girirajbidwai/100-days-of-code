class Solution {
public:
    int getNextJobCurr(vector<vector<int>>& event,int left,int key){
        int right=event.size()-1;
        int nextCurr=event.size();
        while(left<=right){
            int mid=(left+right)/2;
            if(event[mid][0]>=key){
                nextCurr=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return nextCurr;
    }
    int maxProfitJob(int curr,vector<vector<int>>& event,vector<int>& dp){
        if(curr==event.size()) return 0;
        if(dp[curr]!=-1) return dp[curr];
        int skipJob=maxProfitJob(curr+1,event,dp);
        int nextCurr=getNextJobCurr(event,curr,event[curr][1]);
        int doJob=event[curr][2]+maxProfitJob(nextCurr,event,dp);
        return dp[curr]=max(skipJob,doJob);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> event;
        for(int i=0;i<startTime.size();i++){
            event.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(event.begin(),event.end());
        vector<int> dp(event.size(),-1);
        return maxProfitJob(0,event,dp);        
    }
};
