class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<long long> pq(nums.begin(), nums.end());
        
        long long ans = 0;
        
        while (k > 0) {
            long long max_elem = pq.top(); 
            pq.pop();  
            ans += max_elem; 
            pq.push(ceil(max_elem / 3.0));
            k--;
        }
        
        return ans;
    }
};