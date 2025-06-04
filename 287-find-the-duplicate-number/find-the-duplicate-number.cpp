class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1 , high = nums.size() - 1 , mid , ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            int count = 0;
            for(int &i : nums)
                count += (i <= mid);
            if(count > mid)
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};

/*
All numbers & answer in range [1..n],
So, binary search over possible answer.
If count[numbers <= mid] > mid then there is sure a duplicate in range[low..mid]. Otherwise the count would have been exactly mid.
*/