class Solution {
public:
    struct node{
        char lc , rc;
        int pref , suff , total , longest;
        node(char c = '#'){
            lc = rc = c;
            pref = suff = total = longest = 1;
        }
    };
    vector <node> tree;
    node merge(node left , node right){
        node ans = node();
        ans.total = left.total + right.total;
        ans.longest = max(left.longest , right.longest);
        if(left.rc == right.lc) // middle portion same.
            ans.longest = max(ans.longest , left.suff + right.pref);
        ans.pref = left.pref + (left.pref == left.total and left.rc == right.lc ? right.pref : 0);
        ans.suff = right.suff + (right.suff == right.total and left.rc == right.lc ? left.suff : 0);
        ans.lc = left.lc , ans.rc = right.rc;
        return ans;
    }
    // left.pref , left.suff , right.pref , right.suff
    // pref/suff length of prefix/suffix made of same characters.
    // total = segment length
    // longest = max len of same character substring in the segment
    // when two nodes are merged, pref can be extend if and only if left.pref is the whole segment i.e : left.pref == left.total
    // then left.pref can be concatenated with right.pref Otherwise can't. If there is at least 1 length suffix in the left child, they can't
    // be merged as a single-same-character-substring.
    void build(int treeIdx, int low, int high, const string &s) {
        if (low == high) {
            tree[treeIdx] = node(s[low]);
            return;
        }
        int mid = (low + high) / 2;
        build(2 * treeIdx + 1, low, mid, s);
        build(2 * treeIdx + 2, mid + 1, high, s);
        tree[treeIdx] = merge(tree[2 * treeIdx + 1], tree[2 * treeIdx + 2]);
    }
    void update(int treeIdx, int low, int high, int i, char c){
        if (low == high)
        {
            tree[treeIdx] = node(c);
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * treeIdx + 1, low, mid, i, c);
        else
            update(2 * treeIdx + 2, mid + 1, high, i, c);
        tree[treeIdx] = merge(tree[2 * treeIdx + 1] , tree[2 * treeIdx + 2]);
    }
    vector<int> longestRepeating(string s, string qC, vector<int>& qI) {
        int n = s.size() , m = qC.size();
        tree.resize(4 * n);
        build(0 , 0 , n - 1 , s);
        vector<int> ans;
        for(int i = 0 ; i < m ; i++){
            int idx = qI[i];
            char c = qC[i];
            update(0 , 0 , n - 1 , idx , c); // nothing said about reverting each query
            ans.push_back(tree[0].longest); // tree[0] contains segment [0 , n - 1]
        }
        return ans;
    }
};