class Solution {
public:
    int maxDistance(string s, int k) {
        vector <unordered_set <char>> dir = {{'N' , 'E'} , {'N' , 'W'} , {'E' , 'S'} , {'W' , 'S'}};
        int ans = 0;
        for(auto d : dir){
            int dist = 0 , move = k;
            for(char &c : s){
                if(d.contains(c))
                    dist++; // we go only in diagonal direction , increasing our dist.
                else if(move) // any other direction decrease our dist, unless we have some k to change that direction.
                    dist++ , move--;
                else dist--; // no movs left either, no choice but to decrease the distance.
                ans = max(ans , dist);
            }
        }
        return ans;
    }
};

/*
Infinite plane.
    N
  W   E
    S
N -> {0 , -1}
S -> {0 , 1}
W -> {-1 , 0}
E -> {0 , 1}
Find max manhattan distance achievable at any time. 
maximize the minimum manhattan distance by modifying at most "k" directions. Binary search??
Taken from other's solution.
Going at only diagonal increases distance. Going in any other direction undo's a move.
Example: going NE increases. Left dir are : W , S which is inverse to N , E. So going in W,S effectively undo a move in the direction W , S.
So there are four diagonals and simulate for each. We modify the first k chars.
*/