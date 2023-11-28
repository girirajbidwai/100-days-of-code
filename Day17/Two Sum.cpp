vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n) 
{
    sort(arr.begin(),arr.end());
    vector<pair<int, int>> result;
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==target){
        result.push_back({arr[i], arr[j]});
        i++;j--;
        }
        else if(arr[i]+arr[j]>target){
            j--;
        }
        else if(arr[i]+arr[j]<target){
            i++;
        }
    }
    if(result.size()==0){
      result.push_back({-1,-1});
    }
    return result;
}
