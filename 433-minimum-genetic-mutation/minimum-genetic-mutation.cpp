class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set <string> allowed(bank.begin() , bank.end());
        unordered_map <string,bool> visit;
        queue <string> q;
        q.push(startGene);
        visit[startGene] = true;
        int time = -1;
        string valid = "ATGC";
        while(not q.empty()){
            int n = q.size();
            time++;
            while(n--){
                string s = q.front(); q.pop();
                visit[s] = true;
                if(s == endGene)
                    return time;
                for(int i = 0 ; i < s.size() ; i++)
                    for(char c : valid){
                        char ch = s[i];
                        if(c != ch){
                            s[i] = c;
                            if(allowed.contains(s) and not visit[s])
                                q.push(s);
                            s[i] = ch;
                        }
                    }
            }
        }
        return -1;
    }
};