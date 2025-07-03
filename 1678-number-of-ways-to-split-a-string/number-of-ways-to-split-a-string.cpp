class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(string s) {
        int one = count(s.begin(), s.end(), '1'), n = s.size();
        if (one % 3 != 0)
            return 0;
        if (one == 0)
            return (1ll * (n - 1) * (n - 2) / 2) % mod;

        int block = one / 3, cnt = 0, first = 0, second = 0;
        for (char &c : s) {
            cnt += (c == '1');
            if (cnt == block) first++;
            else if (cnt == 2 * block) second++;
        }
        return (1ll * first * second) % mod;
    }
};


/*
Have to split s into three strings such that each has equal 1
return number of ways % mod

Fixing two points breaks the string into three parts.
each block should have count('1') / 3 ones
after this amount of 1, every new 0 makes a new way,

One edge Case is all 0
n - 1 positions to fix the first block ending point
n - 2 positions to fix second block
divide by 2 for overcounting. S secondate for 0000 & 000000
*/