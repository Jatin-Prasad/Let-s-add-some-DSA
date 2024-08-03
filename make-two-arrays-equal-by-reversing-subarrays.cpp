class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        int i=0;
        while(i<arr.size())
        {
            if(arr[i]==target[i]){
             i++;
            }
            else 
            return false;
        
        }
        return true;        
    }
};
