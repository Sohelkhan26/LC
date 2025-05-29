class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1e9 + 7;
        for(int i = n - 1 ; i >= 0 ; i--){
            long long mask = 1ll << i;
            if((a & mask) == (b & mask)) // both bit same either 0,0 or 1,1
                a |= mask , b |= mask; // either way set them to 1,1
            else{
                if(a > b)
                    swap(a , b);
                a |= mask; // a is smaller, set i'th bit of 'a' to 1 and make it closer to b
                b &= (~mask); // set i'th bit of 'b' to 0
            }
        }
        return ((a % mod) * (b % mod)) % mod;
    }
};

/*
Fact: For fixed sum S = A + B, the product A * B is maximized when A = B.
Our case is fixed sum also , because we can set only one bit to 1, other to 0.
If bits are equal, we flip both to 1 to make both larger.
If bits are different, we try to balance them by increasing the smaller and decreasing the larger → giving a higher product.
*/