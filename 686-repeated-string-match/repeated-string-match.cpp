class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size() , m = b.size();
        long long base = 109 , mod = 1e9 + 9 , aHash = 0 , bHash = 0 , power = 1;
        for(char &c : b){
            bHash = (bHash * base + (c - 'a' + 1)) % mod;
            power = (power * base) % mod;
        }
        for(int i = 0 ; i < max(2 * m , 2 * n) ; i++){
            int j = i % n;
            aHash = (aHash * base + (a[j] - 'a' + 1)) % mod;
            if((i + 1) > m)
                aHash = (aHash - (1LL * (a[(i - m) % n] - 'a' + 1) * power) % mod) % mod; // don't forget to mod index i by n
            if(aHash < 0)
                aHash += mod;

            if(aHash == bHash) 
                return (i + 1 + n - 1) / n; // shortcut for ceil(1.0 * (i + 1) / n) 
        }
        return -1;
    }
};

/*
Given two strings, return min times 'a' need to be appended to itself such that 'b' is a substring in 'a'.
Instead of appending 'a' to itself until it's size exceeds b.size() we can simulate this process by looping from [0..2 * m + n] 
And keep a 'm' size window to check if they match. Variables are taken such that collision don't occur. In case of collision, do manual checking. But this one passes just fine.
*/