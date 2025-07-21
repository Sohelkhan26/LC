class Solution {
public:
    int mod = 1337;
    int modPow(int n , int a){
        if(a == 0)
            return 1;
        int ans = modPow(n , a / 2);
        ans = (1ll * ans * ans) % mod;
        if(a % 2)
            ans = (1ll * ans * n) % mod;
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for(int &digit : b)
            ans = (1LL * modPow(ans , 10) * modPow(a , digit)) % mod;
        return ans;
    }
};

/*
b is some array.
number of b will be constructed as from right to left:
b[0] * 10^0 + b[1] * 10^1 + b[2] * 10^2..... b[n] * 10^n

we have to calculate a ^ b with mod
a ^ (x + y) = a ^ x * a ^ y
Combine the both and calculate the answer with fast exponentiation.
*/