class Solution {
public:
    int minOperations(int k) {
        if(k == 1)
            return 0;
        int low = 1 , high = 1e5 , mid , ans = -1;
        auto isPossible = [&](int total){
            int l = 0, r = total;
            while (l <= r) {
                int dup = (l + r) / 2;
// now we want to find the number "x" after some number of 1st operation
// we have to find smallest number "x" s.t x * (dup + 1) >= k -> x = ceil(k / (dup + 1))
                int x = (k + dup) / (dup + 1);  // same as ceil(k / (dup + 1))
                int inc = x - 1;
                if (inc + dup <= total) {
                    return true;  // feasible
                } else {
                    l = dup + 1;  // too few duplications, try more
                }
            }
            return false;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isPossible(mid))
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }        
        return ans;
    }
};

/*
Binary search over total operation.
inc : number of 1st opeartion
dup : number of second operation.
total = (1 + inc) * (dup + 1) , initial number = 1 , use inc steps to make it "X" , now duplicate it "dup" times , now there is 1 original and "dup" duplicate values, resulting in "total"
*/
