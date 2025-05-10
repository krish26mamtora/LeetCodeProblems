class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;

        for (int n : nums1)
        {
            sum1 += n;
            if (n == 0)
            {
                zero1 += 1;
                sum1 += 1;
            }
        }

        for (int n : nums2)
        {
            sum2 += n;
            if (n == 0)
            {
                zero2 += 1;
                sum2 += 1;
            }
        }
        if (sum1 < sum2 && zero1 == 0)
            return -1;
        if (sum2 < sum1 && zero2 == 0)
            return -1;

        return max(sum1, sum2);
    }
};
