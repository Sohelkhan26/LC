class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff , int k) {
        vector<pair<int,int>> perf;
        for(int i = 0 ; i < n ; i++)
            perf.push_back({eff[i] , speed[i]});
        sort(perf.rbegin() , perf.rend());
        priority_queue <int , vector<int> , greater<> > pq;
        long ans = 0 , mod = 1e9 + 7 , totalSpeed = 0;
        for(auto [e , s] : perf){
            if(pq.size() == k){
                totalSpeed -= pq.top();
                pq.pop();
            }
            pq.push(s);
            totalSpeed += s;
            ans = max(ans , totalSpeed * e);
        }
        return ans % mod;
    }
};
/*
The trick is to find the best performance for each efficiency eff[i].
আমরা সর্বোচ্চ k সংখ্যক Engineer নিতে পারবো। তাদের মধ্যে একজন না একজনের মিনিমাম efficiency থাকবেই এই efficincy ওয়ালাকে রাখতেই হবে , তাই যার স্পিড সবচেয়ে কম তাকে বাদ দিতে হবে এবং performance calculate করতে হবে। 
*/