class Solution {
public:
    vector<int> tree;
    void update(int treeIdx, int low, int high, int i) {
        if (low == high) {
            tree[treeIdx] += 1;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * treeIdx + 1, low, mid, i);
        else
            update(2 * treeIdx + 2, mid + 1, high, i);
        tree[treeIdx] = (tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2]);
    }
    int query(int i, int low, int high, int left, int right) {
        if (right < low || high < left)
            return 0;
        if (low >= left && high <= right)
            return tree[i];
        int mid = low + (high - low) / 2;
        int l = query(2 * i + 1, low, mid, left, right);
        int r = query(2 * i + 2, mid + 1, high, left, right);
        return l + r;
    }
    int createSortedArray(vector<int>& nums) {
        int n = *max_element(nums.begin() , nums.end()) + 1 , ans = 0 , mod = 1e9 + 7;
        tree.resize(4 * n);
        for(int &i : nums){
            int a = query(0 , 0 , n , 0 , i - 1);
            int b = query(0 , 0 , n , i + 1 , n);
            ans = (ans + min(a , b)) % mod;
            update(0 , 0 , n , i);
        }
        return ans;
    }
};