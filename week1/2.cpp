// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

class Solution
{
public:
    int bitlen(int n)
    {
        return log2(n) + 1;
    }
    int concatenatedBinary(int n)
    {
        long ans = 0;
        int M = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            ans = ((ans << bitlen(i)) % M + i) % M; // modulo ke baad bna ans bghi chal gya
        }
        return ans;
    }
};