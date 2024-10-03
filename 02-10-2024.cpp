class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>second=arr;
        sort(arr.begin(),arr.end());
        map<int,int>se;
        int x=arr.size();
        int c=1;
        for(int i=0;i<x;i++){
            if(!se[arr[i]]){
                se[arr[i]]=c++;
            }
        }
         for(int i=0;i<x;i++){ 
            arr[i]=(se[second[i]]);
        }
        return arr;
    }
};