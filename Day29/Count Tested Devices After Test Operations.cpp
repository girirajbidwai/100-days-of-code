class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int ans = 0;
        for(int i : b){
            if(i-ans > 0) ans++;
        }
        return ans;
    }
};
