class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int prev= arr[0][1];
        int ans=0;
        for(int i=1;i<arr.size();i++)
        {
          if(arr[i][0]<prev)
          {
            ans++;
            prev=min(prev,arr[i][1]);
          }
          else 
          {
            prev=arr[i][1];
          }
        }
        return ans;
    }
};
