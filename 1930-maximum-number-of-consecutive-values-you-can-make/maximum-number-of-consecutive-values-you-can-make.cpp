class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int canMake = 0;
        sort(coins.begin() , coins.end());
        for(int &coin : coins){
            if(coin > canMake + 1)
                return canMake + 1;
            canMake += coin;
        }
        return canMake + 1;
    }
};