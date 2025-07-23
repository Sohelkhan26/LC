class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map <int,vector<int>> diags;
        int n = mat.size() , m = mat[0].size();

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                diags[i + j].push_back(mat[i][j]);

        bool flip = true;
        vector <int> ans;

        for(auto &[ _ , v ] : diags){
            if(flip)
                reverse(v.begin() , v.end()) , flip = false;
            else flip = true;
            ans.insert(ans.end() , v.begin() , v.end());
        }
        return ans;
    }
};