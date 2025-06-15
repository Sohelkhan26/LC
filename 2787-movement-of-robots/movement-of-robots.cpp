class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size() , mod = 1e9 + 7;
        long long ans = 0 , pref = 0;
        vector <long long> dist(n);
        for(int i = 0 ; i < n ; i++)
            dist[i] = 0ll + nums[i] + (s[i] == 'R' ? d : -d);
        sort(dist.begin() , dist.end());
        for(int i = 0 ; i < n ; i++){
            ans = (ans + 1ll * dist[i] * i - pref) % mod; 
            pref = (pref + dist[i]) % mod;
        }
        return ans;
    }
};

/*
co-ordinates and direction of robots is given.
find out their position after 'd' seconds.
If they collide they change their direction.
and return sum of distance between every pair of robot. 
robot <= 1e5, can't iterate every pair.
two parts. 
1. find out final position.
2. return sum of distances
d is very large. 1e9

This problem is solely solvable by observation: collision don't change the direction of robot. We don't have identify each robot distinctly.
So,although after collision they swap direction, we can swap their identity too. 
they go the way they were going. So, after 'd' seconds they will be at nums[i] +/- d position.
And for the distance between each pair, we sort they array and add contribution to the answer for each position.
Important fact is the problem asks us to find pairs (j < i)
both (i > j) and (j < i) are same. So, a position should only be paired with all the previous robots. So, i'th position should be compared 'i' times.
*/