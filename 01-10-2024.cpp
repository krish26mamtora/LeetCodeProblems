class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
      int x = arr.size();
      unordered_map<int,int>m;
      for(int i=0;i<x;i++){
        m[((arr[i]%k)+k)%k]++;
      }
      if(m[0]%2!=0){
        return false;
      }
    for(int i=1;i<k;i++){
        if(m[i]!=m[k-i]){
            return false;
        }
    }
    return true;
    }
};