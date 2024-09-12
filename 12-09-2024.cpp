class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int  first[26];
        int l1 = allowed.length();
        for(int i=0;i<l1;i++){
            first[allowed[i]-97]++;
        }
        int l2 = words.size();
        int isnot = 0;
        for(int i=0;i<l2;i++){
            string s = words[i];
            for(int j=0;j<s.length();j++){
                if(first[s[j]-97]<=0){
                    isnot++;
                    break;
                }
            }
        }
        return l2-isnot;
    }
};