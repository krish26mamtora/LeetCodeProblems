class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> words1;
        vector<string> words2;
        int l1 = s1.length();
        int l2 = s2.length();
        vector<string>ans;
        string temp = "";
      for(int i = 0; i < l1; i++) {
            if(s1[i] != ' ') {
                temp += s1[i];
            } else {
                words1.push_back(temp);
                temp = "";
            }
        }
        if(!temp.empty()) {
            words1.push_back(temp);
        }

        temp = "";
        for(int i = 0; i < l2; i++) {
            if(s2[i] != ' ') {
                temp += s2[i];
            } else {
                words2.push_back(temp);
                temp = "";
            }
        }
        if(!temp.empty()) {
            words2.push_back(temp);
        }
        unordered_map<string,int>match1;
        for(int i=0;i<words1.size();i++){
            match1[words1[i]]++;
        }
         unordered_map<string,int>match2;
          for(int i=0;i<words2.size();i++){
            match2[words2[i]]++;
        }

        for(const auto&word :match1 ){
            if(word.second==1 && match2.find(word.first)==match2.end()){
                ans.push_back(word.first);
            }
        }
       for(const auto&word: match2){
            if(word.second==1 && match1.find(word.first)==match1.end()){
                ans.push_back(word.first);
            }
        }
        return ans;
    }
};