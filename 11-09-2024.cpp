class Solution {
public:
    string findbinary(int n){
        string ans="";
          while(n>0){
            ans.push_back(n%2);
            n = n/2;
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
     
    string b1 = findbinary(start);
    string b2 = findbinary(goal);
    int l1 = b1.length();
    int l2 = b2.length();
    if(l1<l2){
        for(int i=1;i<=l2-l1;i++){
            b1.push_back(0);
        }
    }
       if(l2<l1){
        for(int i=1;i<=l1-l2;i++){
            b2.push_back(0);
        }
    }
   
    int len = max(l1,l2);
    int c = 0;
    for(int i=0;i<len;i++){
        if(b1[i]!=b2[i]){
            c++;
        }
    }
    return c;
    }
};