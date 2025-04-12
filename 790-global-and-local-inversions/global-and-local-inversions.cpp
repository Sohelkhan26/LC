class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size() , maxNumber = 0;
        for(int i = 0 ; i < n - 2 ; i++){
            maxNumber = max(maxNumber , nums[i]);
            if(maxNumber > nums[i + 2])
                return false;
        }
        return true;
    }
};

/*
Use distance function to determine the count of (nums[j] < nums[i]).
set uses bidirectional iterator , not random access iterator so(- prev.begin()) don't work.
Binary search to find global inversion results in TLE.
Observation:
local inversion is a subset of global inversion.
So for any index if it produces additional global inversion, return false.
[i] , [i + 1] local inversion check
so, do [i] , [i + 2] for global inversion check.
*/