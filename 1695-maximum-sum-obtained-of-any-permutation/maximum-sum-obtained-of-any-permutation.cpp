class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size() , overlap = 0 , ans = 0 , mod = 1e9 + 7;
        vector <int> line(n + 1);
        for(auto &r : requests)
            line[r[0]] += 1 , line[r[1] + 1] -= 1;
        for(int i = 1 ; i < n ; i++)
            line[i] += line[i - 1];
        sort(line.rbegin() , line.rend());
        sort(nums.rbegin() , nums.rend());
        for(int i  = 0 ; i < n ; i++)
            ans = (ans + 1ll * line[i] * nums[i]) % mod;
        return ans;
    }
};

/*
You are to modify the nums at most once. Not for each query.
Find max sum of query sum.
Every number should contribute some amount to the answer.
We can rearrange the numbers so, those indices that are most accessed in the queries should be assigned highest values. So , line sweep determines which indices are accessed most frequently.
*/