class Solution {
public:
    double maxAmount(string init , vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map <string,double> dist;
        dist[init] = 1.0;
        auto bellman = [&](vector<vector<string>> &pairs , vector<double> &rate){
            for(int t = 0 ; t < pairs.size() ; t++){
                for(int i = 0 ; i < pairs.size() ; i++){
                    string from = pairs[i][0] , to = pairs[i][1];
                    dist[to] = max(dist[to] , rate[i] * dist[from]);
                    dist[from] = max(dist[from] , 1.0 / rate[i] * dist[to]);
                }
            }
        };
        bellman(pairs1 , rates1);
        bellman(pairs2 , rates2);
        return dist[init];
    }
}; 