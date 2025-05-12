class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size() , ans = INT_MIN;
        if(n == 1 and k % 2)
            return -1;
        for(int i = 0 ; i < n and i < k - 1 ; i++)
            ans = max(ans , nums[i]);
        if(k < n)
            ans = max(ans , nums[k]);
        return ans;
    }
};

/*
if n == 1:
k even : we can remove and top it again until k run out.
k even : need at least 2 operation to put the removed element on top. So extra one operation will be used to remove it. return -1.
Otherwise be greedy: We can either:
1.Take the first k - 1 element and stand by. Use the remaining move to put max element from standby to top. 
2.Remove k elements. And if there is still one element that could be our answer.
Out of the two case take the maximum one.

*/