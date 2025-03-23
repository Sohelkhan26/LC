class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seat) {
        unordered_map <int,int> mp;
        for(auto it : seat)
            mp[it[0]] += (1 << it[1]);
        int one = ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)); // first half
        int three = ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)); // last half
        int two = ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)); // middle half
        // first half means 2,3,4,5th seat.
        int ans = (n - mp.size()) * 2;
        for(auto it : mp){
            int reserve = it.second , group = 0;
            if((reserve & one) == 0)
                group++;
            if((reserve & three) == 0)
                group++;
            if((reserve & two) == 0)
                group = (group == 0) ? 1 : group;
            ans += group;
        }
        return ans;
    }
};

/*
We can allocate maximum two group in a row. 
For rows that have at least one reserved seat, calculate how much groups can be allocated. For the rest, 2 groups can be allocated.

*/