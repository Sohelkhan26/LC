class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector <long long> pref = {candiesCount[0]};
        vector <bool> ans;
        for(int i = 1 ; i < n ; i++)
            pref.push_back(pref.back() + candiesCount[i]);
        for(auto &q : queries){
            int i = q[0] , day = q[1] , limit = q[2];
            bool ok = true;
            if(day > pref[i] - 1)
                ok = false;
            long long total = (i > 0 ? pref[i - 1] : 0);
            if(day < total / limit)
                ok = false;
            ans.push_back(ok);
        }
        return ans;
    }
};

/*
candiesCount[i] of candy of i'th type
to eat i'th type candy, all [0..i - 1]th type candy should be eaten.

query limit applies to any day

i'th type candy d'th favorite day
i'th type candy should remain at least 1
all i - 1th type eaten
at least 'd' candy eaten
can't cross daily limit. 

before fav day, fav candy eaten, possible when? d > pref[i] - 1 even eating 1 candy per day will exhaust fav candy
pref[i - 1] candy should be eaten in the first d - 1 day
without breaking limit. if limit breaks return false????

*/