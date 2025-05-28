class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int canMake = 1 , n = coins.size();
        sort(coins.begin() , coins.end());
        for(int i = 0 ; i < n and coins[i] <= canMake ; i++)
            canMake += coins[i];
        return canMake;
    }
};

/*
Like induction.
If we can make number in range [0..k] , then after adding an number x we can make all the numbers up to x + k
we can make [0..k] = [0 , ... , k - 3 , k - 2 , k - 1 , k] by adding them with previous values of k we can make numbers in range [x , x + k]
We are required to find max consecutive integers we can make. Suppose we can make numbers in range [0..canMake] so, after we can make numbers in range [x..canMake + x] , in order to be consecutive x <= canMake + 1 otherwise there will be a gap.
*/