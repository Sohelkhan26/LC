class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long a = 0 , b = 0;
        int z1 = 0 , z2 = 0;
        for(int &i : nums1)
            i == 0 ? z1++ , a++ : a += i;
        for(int &i : nums2)
            i == 0 ? z2++ , b++ : b += i;
        if(z1 == 0 and a < b) // no way to increase sum(nums1)
            return -1;
        if(z2 == 0 and a > b)
            return -1; 
        return max(a , b);
    }
};
/*
have to replace all 0 with +ve number.
have to make sum of both equal.
make all 0 -> 1, then increase a number of the array that has smaller sum.
if no room to increase sum(no 0) and sum is less than the other, return -1
*/