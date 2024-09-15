class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int temp = arr[queries[i][0]];
            int st = queries[i][0]+1;
            int end = queries[i][1];
            for(int j=st ;j<= end;j++){
                temp = temp^arr[j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};