class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size() , ans = 0;
        map <vector <int> , int> mp;
        for(int i = 0 ; i < n ; i++){
            vector <int> col;
            for(int j = 0 ; j < n ; j++)
                col.push_back(grid[j][i]);
            auto it = mp.find(col);
            if(it != mp.end())
                it -> second++;
            else mp.emplace(move(col) , 1);
        }
        for(const auto &row : grid)
            ans += mp[row];
        return ans;
    }
};

/*
This code is taken from votrubac.
move() function doesn't copy the vector, rather it gives up ownership of the internal memory. After that col vector becomes empty.
 
Note that we need to use a three map (ordered map) instead of hash map. For a vector, the three map stops matching when bumps into a discrepancy, while hash map process all elements first to compute a hash.

Note how we optimize the memory usage here. To check if a row exists in map, we are using existing rows. That way, we do not build an entire vector only to find out we have a mismatch on the first element.
*/