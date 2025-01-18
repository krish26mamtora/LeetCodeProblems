class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        vector<int> original = {0};
        for (int i = 0; i < derived.size(); i++)
        {
            original.push_back((derived[i] ^ original[i]));
        }
        bool zero = (original[0] == original[original.size() - 1]);
        original = {1};
        for (int i = 0; i < derived.size(); i++)
        {
            original.push_back((derived[i] ^ original[i]));
        }
        bool one = (original[0] == original[original.size() - 1]);
        return zero | one;
    }
};