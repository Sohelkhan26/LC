class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60);
        int res = 0;
        for (int t : time) {
            res += c[(6000 - t) % 60];
            c[t % 60] += 1;
        }
        return res;
    }
};

/*
(a + b) % val = (a % val + b % val) % val
each number can be either multiple of 60 or not.
If a number is multiple of 60 then i % 60 = 0 this number i will make a valid pair with all numbers that were previously a mutliple of 60
Otherwise it will make valid pair with all numbers = 60 - i that have come before it. So that i + 60 - i = 60 which is a mutliple of 60
*/