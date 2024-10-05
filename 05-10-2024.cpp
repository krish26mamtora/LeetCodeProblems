class Solution {
public:
    bool chekequal(int count1[26],int count2[26]){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int temp = s1[i]-'a';
            count1[temp]++;
        }

        int i=0;
        int windowsize = s1.length();
        int count2[26]={0};

        while(i<windowsize && i<s2.length()){
            int temp = s2[i]-'a';
            count2[temp]++;
            i++;
        }

        if(chekequal(count1,count2)){
            return 1;
        }
        while(i<s2.length()){
            char newchar = s2[i];
            int temp = newchar -'a';
            count2[temp]++;

            char oldchar = s2[i-windowsize];
           int index = oldchar - 'a';
            count2[index]--;

             if(chekequal(count1,count2)){
            return 1;
            }
            i++;
        }
        return 0;
    }
};