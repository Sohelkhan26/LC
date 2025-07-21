class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size() , m = tasks.size() , time = 0 , i = 0;
        vector <int> ans;
        auto compare = [&](pair<int,int> &a , pair<int,int> &b){
            return (a.first > b.first) or (a.first == b.first and a.second > b.second);
        };
        priority_queue <pair<int,int> , vector<pair<int,int>> , decltype(compare) > free(compare) , busy(compare);
        for(int i = 0 ; i < n ; i++)
            free.push({servers[i] , i}); // smallest free server first
        for(int i = 0 ; i < m ; ){
            int t = tasks[i];
            while(not busy.empty() and busy.top().first <= time){ // new servers became free
                auto [freeTime , idx] = busy.top(); busy.pop();
                free.push({servers[idx] , idx});
            }

            if(not free.empty()){
                auto [w , idx] = free.top();
                free.pop();
                busy.push({time + t , idx});
                ans.push_back(idx);
                i++;
                time = max(time , i);
            }else{
                time = busy.top().first;
            }
        }
        return ans;
    }
};