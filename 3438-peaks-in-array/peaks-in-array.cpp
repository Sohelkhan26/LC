class Solution {
public:
    vector <int> nums , tree;
    int n;
    bool isPeak(int i){
        if(i == 0 or i == n - 1)
            return false;
        return (nums[i] > nums[i - 1]) and (nums[i] > nums[i + 1]);
    }

    void build(int root , int low, int high){
        if (low == high){
            tree[root] = isPeak(low);
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * root + 1, low, mid);
        build(2 * root + 2, mid + 1, high);
        tree[root] = (tree[2 * root + 1] + tree[2 * root + 2]);
    }

    void update(int root, int low, int high, int i){ 
        if (low == high){
            tree[root] = isPeak(low);
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * root + 1, low, mid, i);
        else
            update(2 * root + 2, mid + 1, high, i);
        tree[root] = (tree[2 * root + 1] + tree[2 * root + 2]);
    }
    int query(int root , int low , int high , int qL , int qR){ 
        if(qR < low or qL > high)
            return 0;
        if(qL <= low and high <= qR)
            return tree[root];
        int mid = low + (high - low) / 2;
        int l = query(2 * root + 1 , low , mid , qL , qR);
        int r = query(2 * root + 2 , mid + 1 , high , qL , qR);
        return (l + r);
    }
    vector<int> countOfPeaks(vector<int>& a, vector<vector<int>>& queries) {
        n = a.size();
        nums = a;
        tree = vector<int> (4 * n);
        build(0 , 0 , n - 1);
        vector <int> ans;
        for(auto &q : queries){
            if(q[0] == 1)
                ans.push_back(query(0 , 0 , n - 1 , q[1] + 1 , q[2] - 1)); // first & last element of an array/subarray can't be peak
            else{
                int i = q[1] , val = q[2];
                nums[i] = val;
                update(0 , 0 , n - 1 , i);
                if(i - 1 >= 0) // updating can affect i - 1 , i , i + 1 indices either could be peak
                    update(0 , 0 , n - 1 , i - 1);
                if(i + 1 < n)
                    update(0 , 0 , n - 1 , i + 1);
            }
        }
        return ans;
    }
};
