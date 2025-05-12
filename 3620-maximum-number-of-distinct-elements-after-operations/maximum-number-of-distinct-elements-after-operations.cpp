class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int prev = INT_MIN , unique = 0;
        for(int n : nums){
            int lower = n - k , upper = n + k;
            if(prev < lower) // we can make n at most [n - k] low, making it any lower than this is not possible. So, if the previous number is less than lowerBound than we assign lowest possible [n - k] to n. 
                prev = lower , unique++;
            else if(prev < upper) // If we cannot assign n - k because it would overlap with prev or be too close, we try the next smallest value > prev, i.e., prev + 1.
                prev++ , unique++;
            // if prev >= upper , as nums is sorted , no way n can be made uinque
        }
        return unique;
    }
};
