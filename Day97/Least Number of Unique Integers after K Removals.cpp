class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp; 
        for(int i : arr){
           mp[i]++;
        }

        vector<pair<int,int>> v;
        for(auto &i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        int ans = v.size();
        cout<<ans;
        for(int i = 0;i< v.size(); i++){
            if(v[i].first < k){
                k -= v[i].first;
                ans--;
            }
            else if(v[i].first == k) return --ans;
            else return ans;
        }
        return ans;
    }
};
