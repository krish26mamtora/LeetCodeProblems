class Solution {
public:
    int findTheLongestSubstring(string s) {
    unordered_map<char,int> hash = {{'a',1},{'e',2},{'i',4},{'o',8},{'u',16}};
    vector<int> seen(32,-1);
    int mask = 0;
    int maxlen = 0;
    int l = s.size();
    for(int i=0;i<l;i++){
        mask = mask^hash[s[i]];
        if(mask!=0 && seen[mask]==-1){
            seen[mask]=i;
        }
        maxlen = max(maxlen,i-seen[mask]);
    }
    return maxlen;
    }
};