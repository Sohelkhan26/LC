class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return n;
        int one = 0;
        while(n > 0)
            n >>= 1 , one++;
        return pow(2 , one);
    }
};

/*
nums is a permutation [1 .. n]
every number less than n will have up-to MSB(n). Smaller number won't have a set bit that exceeds the MSB of n. 
Every bit contributes some, pow(2 , x) where x is the position of the bit. If a same bit contribute twice(in two diff number) then overall contribution will be 0.
So, xoring max-number "n" with any other number won't result in number greater than n.

*/