class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        queue<int> q;
        
        for(int i = 0; i < bank.size(); i++){
            int tmp = 0;
            for(int j = 0; j < bank[0].size(); j++){
                if(bank[i][j] == '1'){
                    tmp+=1;
                }
            }
            if(tmp) q.push(tmp);
        }
        int a=0;
        int b=0;
        if(q.size()) a = q.front();
        q.pop();
        if(q.size()) b = q.front();
        q.pop();
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            ans += (a*b);
            a = b;
            b = q.front();
            q.pop();
        }
        ans += (a*b);
        return ans;
    }
};
