class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flip = 0 , n = nums.size();
        for(int i : nums){
            if((i + flip) % 2 == 0)
                flip++;
        }
        return flip;
    }
};