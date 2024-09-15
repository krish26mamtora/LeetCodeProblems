class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        int ans=0;
        int max = 0;
       for(int i=0;i<n;i++){
           if(nums[i]>max){
            max = nums[i];
           }
       }
        for(int i=0;i<n;i++){
            if(nums[i]==max){
                c++;
            }
            if(nums[i]!=max){
                c=0;
            }
            if(c>ans){
                ans=c;
            }
        }
        return ans;
    }
};