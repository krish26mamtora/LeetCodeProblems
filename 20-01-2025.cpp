class Solution
{

public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size();    // rows
        int n = mat[0].size(); // column
        unordered_map<int, pair<int, int>> numtocheck;
        vector<int> rowcount(m);
        vector<int> colcount(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int value = mat[i][j];
                numtocheck[value] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            auto [row, col] = numtocheck[arr[i]];
            rowcount[row]++;
            colcount[col]++;
            if (rowcount[row] == n || colcount[col] == m)
            {
                return i;
            }
        }
        return -1;
    }
};