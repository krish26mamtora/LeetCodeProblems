class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int ans = 0;
        // int row = grid.size();
        // int col = grid[0].size();
        vector<int> colcount(grid.size(), 0);
        vector<int> rowcount(grid[0].size(), 0);
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    rowcount[col]++;
                    colcount[row]++;
                }
            }
        }
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    ans += rowcount[col] > 1 || colcount[row] > 1;
                }
            }
        }
        return ans;
    }
};