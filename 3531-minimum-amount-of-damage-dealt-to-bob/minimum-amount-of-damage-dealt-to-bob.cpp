class Solution {
public:
    typedef pair<int,int> p;
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long ans = 0 , n = damage.size() , total = 0;
        vector<pair<int,int>> v;
        for(int i = 0 ; i < n ; i++){
            int time = ceil(health[i] / (power * 1.0));
            total += damage[i];
            v.push_back({damage[i] , time});
        }
        sort(v.begin() , v.end() , [&](auto a , auto b){
            return (double)a.first / a.second > (double)b.first / b.second;
        });
        for(auto [d , t] : v)
            ans += (total * t) , total -= d;
        return ans;
    }
};
/*
Be greedy, take out the enemy that deals most damage per unit of time.
*/