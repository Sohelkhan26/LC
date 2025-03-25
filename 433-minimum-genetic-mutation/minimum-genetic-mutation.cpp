class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set <string> allowed(bank.begin() , bank.end());
        if(not allowed.contains(endGene))return -1;
        queue <string> q;
        q.push(startGene);
        int time = -1;
        string valid = "ATGC";
        while(not q.empty()){
            int n = q.size();
            time++;
            while(n--){
                string s = q.front(); q.pop();
                allowed.erase(s); // erase it so isn't revisited.
                if(s == endGene)
                    return time;
                for(char &c : s){
                    for(char v : valid){
                        char prev = c;
                        c = v;
                        if(allowed.contains(s))
                            q.push(s);
                        c = prev;
                    }
                }
            }
        }
        return -1;
    }
};