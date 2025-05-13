class Solution {
public:
    int minOperations(int k) {
        if(k == 1)
            return 0;
        int low = 1 , high = 1e5 , mid , ans = -1;
        auto isPossible = [&](int total){
            for(int dup = total ; dup >= 1 ; dup--){
                int incOp = (total - dup);
                if(1ll * (incOp + 1) * (dup + 1) >= k)
                    return true;
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
