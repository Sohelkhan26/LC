class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector <long long> ans(arr.size());
        unordered_map <int,vector<int>> mp;
        for(int i = 0 ; i < arr.size() ; i++)
            mp[arr[i]].push_back(i);
        for(auto it : mp){
            vector <int> &nums = it.second;
            int n = nums.size();
            long long pref = 0 , total = 0;
            for(int &i : nums)
                total += i;
            for(int i = 0 ; i < n ; i++){
                int j = nums[i]; // nums[i] is index of some number we are not concerned with.
                long long suff = total - pref - j;
                ans[j] += (1ll * i * nums[i]);
                ans[j] -= pref;
                ans[j] += suff; 
                ans[j] -= 1ll * (n - i - 1) * nums[i];
                pref += nums[i];
            }
        }
        return ans;
    }
};

/*
Approach is obvious. For every element store all occurance indices.
For the calculation part we can't use O(n ^ 2) method. So, prefix sum was used.
indices stored in ascending, for every element , same element can occur before this index or after this index. 
Sum of previous index is "pref". So, partial answer for until index i is: (i * nums[i] - pref)
suff is sum of elements in range [i + 1 .. n] , they are all greater than nums[i]
So, partial answer for right portion(same element occuring after this index): suff - (n - i - 1) * nums[i]
ans[i] is directly calculated. As indices are unique the inner loop will run no more than O(n), n being the length of arr. 
*/