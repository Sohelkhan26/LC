class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_map <int,int> pairing;
        for(auto &p : pairs)
            pairing[p[0]] = p[1],
            pairing[p[1]] = p[0];
        auto find = [&](int x , int y){
            for(int u : preferences[x]){
                if(u == y)
                    return false;
                bool ok = false;
                for(int v : preferences[u]){
                    if(v == pairing[u])
                        break;
                    if(v == x)
                        ok = true;
                }
                if(ok)
                    return true;
            }
            return false;
        };
        int unhappy = 0;
        for(auto &it : pairs){
            int x = it[0] , y = it[1];
            unhappy += find(x , y);
            unhappy += find(y , x);
        }
        return unhappy;
    }
};

/*
Such a trick problem. 
Preference of every person is given.
A person 'x' is unhappy if there is a person 'u' who is preferred over 'x's current pairing and that person 'u' also prefers 'x' over his current pairing.
*/