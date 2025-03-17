class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0 , n = arr.size() , high = n - 1 , mid , ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] < arr[mid + 1]){
                ans = mid + 1;
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};