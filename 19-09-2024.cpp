class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        int x = expression.size();
        for(int i=0;i<x;i++){
            char temp = expression[i];
            if (temp == '+' || temp == '-' || temp == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(auto a:left){
                    for(auto b:right){
                         if (temp == '+') ans.push_back(a + b);
                        else if (temp == '-') ans.push_back(a - b);
                        else if (temp == '*') ans.push_back(a * b);
                    }
                }
            }
        }
          if (ans.empty()) ans.push_back(stoi (expression));
        return ans;
    }
};