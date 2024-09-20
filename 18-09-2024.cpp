

class Solution {
public:
   static bool compare(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {

       string ans = "";

       vector<string> temp;

            for (int num : nums) {
                temp.push_back(to_string(num));
            }

        sort(temp.begin(), temp.end(), compare);

        if(temp[0]=="0"){
           return "0";
        }
   
        for (string s : temp) {
            ans += s;
        }
        
        return ans;
    }
};