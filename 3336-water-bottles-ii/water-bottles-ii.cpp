class Solution {
public:
    int maxBottlesDrunk(int full, int rate) {
        int ans = 0 , empty = 0;
        while(full > 0){
            ans += full; empty += full;
            if(empty >= rate)
                full = 1 , empty -= rate++;
            else break;
        }
        return ans;
    }
};