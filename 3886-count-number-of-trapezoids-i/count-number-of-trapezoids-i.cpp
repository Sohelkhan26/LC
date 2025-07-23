class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map <int,int> freq;
        for(auto &p : points)
            freq[p[1]]++; // count of points parallel to x axis. No duplicate points in input.
        int ans = 0 , mod = 1e9 + 7 , pref = 0;
        for(auto &[y , n] : freq){
            int curr = (1LL * n * (n - 1) / 2) % mod; // ways to choose 2 points 
            ans = (0LL + ans + 1LL * pref * curr) % mod;
            pref += curr;
        }
        return ans;
    }
};

/*
May seem like geometric problem but actually it's a combinatorics problem. 
A valid trapezium will have it's two sides parallel to x axis, other two sides may be whatever. So, from a parallel set of points, two points can be chosen, these two points can form trapezium for all other parallel set of points. From a parallel set of points 2 points can be chosen in n * (n - 1) / 2 ways. 1st one forms n - 1 pairs with the rest, 2nd one forms n - 2...
their sum = n * (n - 1) / 2 basic observation.
They can form points with all other parallel points, in worst case, there could exist points.length() times of 2 parallel points.
We don't want to loop through the whole frequency array. Prefix sum can help.
Prefix sum of choices.
*/