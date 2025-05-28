class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin() , coins.end());
        long add = 0 , obtainable = 0;
        for(int &coin : coins){
            while(coin > obtainable + 1)
                obtainable += (obtainable + 1) , add++;
            obtainable += coin;
        }
        while(obtainable < target)
            obtainable += (obtainable + 1) , add++;
        return add;
    }
};