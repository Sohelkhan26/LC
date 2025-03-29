class Solution {
public:
    vector<vector<int>> pref;
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        pref.resize(n + 1 , vector<int> (m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] +
                             pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        auto check = [&](int len) { 
            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= m; j++) {
                    if (pref[i + len][j + len] - pref[i + len][j] - pref[i][j + len] + pref[i][j] <= threshold)
                        return true;
                }
            }
            return false;
        };

        int low = 0, high = min(n, m), ans = 0;
        while (low <= high) {
            int len = low + (high - low) / 2;
            if (check(len)) {
                ans = len;
                low = len + 1;
            } else {
                high = len - 1;
            }
        }
        return ans;
    }
};
