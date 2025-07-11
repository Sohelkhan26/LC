class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <int> count(n);
        for(int i = 0 ; i < n ; i++){
            int zero = 0;
            for(int j = n - 1 ; j >= 0 and grid[i][j] == 0 ; j--)
                zero++;
            count[i] = zero; // store trailing zero count at each row
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            // count[i] is current trailing zero count, but to make valid matrix, i'th row should have n - 1 - i trialing zero
            if(count[i] >= n - 1 - i)
                continue;
            int j = i + 1;
            while(j < n and count[j] < n - i - 1)
                j++;
            if(j == n) // we couln't find any row with required trailing zero
                return -1;
            while(i < j) // simulate the swap
                swap(count[j] , count[j - 1]) , ans++ , j--;
        }
        return ans;
    }
};

/*
given square binary grid return minimum swap to make it valid
valid matrix is the one which have all zero above the main diagonal
main diagonal start at 0,0 and end at n - 1 , n - 1
Main observation: Each row must have at least n - i - 1 trailing zero, any more than that is good but less is not acceptable.
*/