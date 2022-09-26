// https://leetcode.com/problems/sum-of-even-numbers-after-queries/submissions/

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {

        vector<int> ret;

        int ans = 0;
        for (auto i : nums)
            if (i % 2 == 0)
                ans += i;
        for (auto i : queries)
        {
            if (nums[i[1]] % 2 == 1 || nums[i[1]] % 2 == -1)
            {
                if (i[0] % 2 == 1 || i[0] % 2 == -1)
                    ans += i[0] + nums[i[1]];
            }
            else
            {
                if (i[0] % 2 == 0)
                    ans += i[0];
                else
                    ans -= nums[i[1]];
            }

            nums[i[1]] += i[0];
            ret.push_back(ans);
        }

        return ret;
    }
};