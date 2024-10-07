class Solution {
public:
    int minLength(string s) {
        while (true) {
            string temp = s;
            for (auto sub : {"AB", "CD"}) {
                size_t pos = s.find(sub);
                if (pos != string::npos) s.replace(pos, 2, "");
            }
            if (temp == s) break;
        }
        return s.length();
    }
};
