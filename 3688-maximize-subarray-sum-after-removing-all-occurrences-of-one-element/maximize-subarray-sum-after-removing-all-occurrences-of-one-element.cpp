class Solution {
public:
    typedef long long ll;
    struct node {
        ll prefix, suffix, total, maxSubarray;
        node(int val = 0) {
            prefix = suffix = total = maxSubarray = val;
        }
        void change(int val) {
            prefix = suffix = total = maxSubarray = val;
        }
    };

    vector<node> tree;

    node merge(node left, node right) {
        node ans;
        ans.total = left.total + right.total;
        ans.prefix = max(left.prefix, left.total + right.prefix);
        ans.suffix = max(right.suffix, right.total + left.suffix);
        ans.maxSubarray = max({left.maxSubarray, right.maxSubarray, left.suffix + right.prefix});
        return ans;
    }

    void build(int root, int low, int high, vector<int>& a) {
        if (low == high) {
            tree[root] = node(a[low]);
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * root + 1, low, mid, a);
        build(2 * root + 2, mid + 1, high, a);
        tree[root] = merge(tree[2 * root + 1], tree[2 * root + 2]);
    }

    void update(int root, int low, int high, int idx, int val) {
        if (low == high) {
            tree[root].change(val);
            return;
        }
        int mid = low + (high - low) / 2;
        if (idx <= mid)
            update(2 * root + 1, low, mid, idx, val);
        else
            update(2 * root + 2, mid + 1, high, idx, val);
        tree[root] = merge(tree[2 * root + 1], tree[2 * root + 2]);
    }

    ll query() {
        return tree[0].maxSubarray;
    }

    long long maxSubarraySum(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, nums);
        ll ans = query();
        
        int mx = *max_element(nums.begin() , nums.end());
        if(mx <= 0)
            return mx;
        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < n; i++)
            idx[nums[i]].push_back(i);

        for (auto &[val, arr] : idx) {
            if (val > 0) continue;
            for (int &i : arr) {
                update(0, 0, n - 1, i, 0);
            }
            ans = max(ans, query());
            for (int &i : arr) {
                update(0, 0, n - 1, i, val);
            }
        }

        return ans;
    }
};
