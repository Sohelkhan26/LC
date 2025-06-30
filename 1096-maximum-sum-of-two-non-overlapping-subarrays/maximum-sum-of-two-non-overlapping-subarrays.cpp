class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        auto solve = [&](int n , int m){
            int first = 0 , second = 0;
            for(int i = 0 ; i < n + m ; i++)
                if(i < n)
                    first += nums[i];
                else second += nums[i];
            int ans = first + second , maxFirst = first; // max possible sum of 1st valid windows are stored in ans
            for(int i = n + m ; i < nums.size() ; i++){
                first += nums[i - m] - nums[i - m - n]; // first window ended at n which is also start of second window.
                second += nums[i] - nums[i - m];
                maxFirst = max(maxFirst , first);
                ans = max(ans , maxFirst + second);
            }
            return ans;
        };
        return max(solve(firstLen , secondLen) , solve(secondLen , firstLen));
    }
};