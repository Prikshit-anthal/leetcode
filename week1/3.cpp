
// https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/

class Solution
{
public:
    string reverseWords(string s)
    {
        string curr = "";
        string ans = "";
        for (auto i : s)
        {
            if (i == ' ')
            {
                reverse(curr.begin(), curr.end());
                ans += (curr + " ");
                curr = "";
            }
            else
                curr.push_back(i);
        }
        reverse(curr.begin(), curr.end());
        return ans + curr;
    }
};