class Solution {
public:
    void findwords(const string &s, vector<string>& words) {
        string word;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word.clear(); 
            } else {
                word.push_back(s[i]);
            }
        }
        if (!word.empty()) {
            words.push_back(word); // Add the last word
        }
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1, words2;

        findwords(sentence1, words1);
        findwords(sentence2, words2);

        if (words1.size() > words2.size()) {
            swap(words1, words2);
        }

        int l = 0;
        while (l < words1.size() && words1[l] == words2[l]) {
            l++;
        }

        int r = words1.size() - 1;
        int w2_pos = words2.size() - 1;
        while (r >= 0 && words1[r] == words2[w2_pos]) {
            r--;
            w2_pos--;
        }

        return l > r;
    }
};
