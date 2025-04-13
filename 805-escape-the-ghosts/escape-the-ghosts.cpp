class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int myDist = abs(target[0]) + abs(target[1]) , ghostDist = 0;
        for(auto g : ghosts)
            if((ghostDist = abs(target[0] - g[0]) + abs(target[1] - g[1])) <= myDist)
                return false;
        return true;
    }
};

/*
Multiple ghosts in single cell confused me.
At first look, it seemed like a mutlisource BFS problem. BFS explore all possible adjacent paths. But we don't need to explore all paths. We can be greedy. I should take the smallest path to avoid the chances of encountering a ghost. Ghost should follow the same strategy. Ghost would like to go to the target and wait for me If it's possible.
Your distance to target is abs(t[0]) + abs(t[1]).
For every ghost g, distance to target is abs(t[0] - g[0]) + abs(t[1] - g[1]).
You need to be closer to target than any ghost to escape.
*/