class Solution {
    
public:
long long dividePlayers(vector<int>& skill) {
        int x = skill.size();
        long long sum=0;
        for(int i=0;i<x;i++){
            sum+=skill[i];
        }
        if(sum%(x/2)!=0){
            return -1;
        }
        long long chemistrySum = 0;
        int check = sum/(x/2); 
        sort(skill.begin(),skill.end());
        int l=0;int r=x-1;
        while(l<r){
            if(skill[l]+skill[r]!=check){
                return -1;
            }
            else{
                chemistrySum+=skill[l]*skill[r];
            }
            l++;
            r--;
        }
        return chemistrySum;
    }
};