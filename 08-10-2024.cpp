class Solution {
public:
    
    int minSwaps(string s) {
        int x=s.length();
        int op=0;
        for(int i=0;i<x;i++){
          {
            if(s[i]=='[') op++;
            if(s[i]==']') 
            {
                if(op>0) op--;
            }
        }
        }
        return (op+1)/2;
    }
};