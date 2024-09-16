class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int x = timePoints.size();
          int ans=INT_MAX;
          vector<int> minutes;

        for(int i=0;i<x;i++){        
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3));

            minutes.push_back(h*60 + m);
       }
    
    sort(minutes.begin(),minutes.end());

    for(int i=0;i<x-1;i++){

      int temp = min(ans,(minutes[i+1]-minutes[i]));
        if(temp<ans){
            ans = temp;
        }
    }
    ans = min(ans,24*60 - minutes.back() + minutes.front());
    return ans;
    }

};