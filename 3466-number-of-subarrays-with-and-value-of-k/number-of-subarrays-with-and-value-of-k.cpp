class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map <int,int> prev;
        for(const int &n : nums){
            unordered_map <int,int> curr; // subarray ending at curr element 'n'
            if((k & n) >= k){ // as AND value decreases over time, if n & k < k that means, n has some 0 bit that need to be 1, no matter how many subarray we extend to this element, their AND value will always be < k
                curr[n] = 1; // subarray with one element = {n}
                for(auto [AND , count] : prev) // extend all previous subarray
                    curr[AND & n] += count;
            }
            ans += curr[k];
            prev = curr;
        }
        return ans;
    }
};

/*
AND value become '<=' for every new element added
Using segment tree and sliding window will work?
maintain a window, use segment tree to find subarray AND
if AND becomes less than k, shrink window.


*/