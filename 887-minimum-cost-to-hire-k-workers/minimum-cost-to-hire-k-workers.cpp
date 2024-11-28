class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector <pair<double,int>> worker;
        for(int i = 0 ; i < wage.size() ; i++)
            worker.push_back({(double)wage[i] / quality[i] , quality[i]});
        sort(worker.begin() , worker.end());
        priority_queue <int> pq;
        double ans = DBL_MAX , totalQuality = 0;
        for(auto &[ratio , q] : worker){
            if(pq.size() == k){
                totalQuality -= pq.top(); pq.pop();
            }
            pq.push(q);
            totalQuality += q;
            if(pq.size() == k)
                ans = min(ans , totalQuality * ratio); // সবাইকেই একই ratio অনুযায়ী বেতন দিতে হবে। তাই সবার আলাদা আলাদা quality track করার কোন দরকারই নাই 
        }
        return ans;
    }
};
/*
আমাদের k group এর worker choose করতে হবে যাতে তারা সবাই একই quality / wage অনুপাতে বেতন পায় এবং এই বেতন মিনিমাম হয়। অর্থাৎ আমাদের শুধু মিনিমাম wage ওয়ালা worker choose করলেই হবে না। যাদের quality / wage ratio কম তাদের নিয়ে শুরু করতে হবে। একটা বিষয় খেয়াল রাখতে হবে যে , কোন গ্রুপের যে woker এর ratio বেশী হবে সেই ratio অনুযায়ী বাকি ওয়ার্কার দেরও বেতন দিতে হবে। তাহলে আমরা ratio অনুযায়ী increasing order এ sort করবো এবং ওয়ার্কার নিতে থাকবো , যতক্ষন না গ্রুপের সাইজ k না হয়। যদি k এর বেশী হয়ে যায় তাহলে একটা ওয়ার্কার বাদ দিতে হবে। কোনটা বাদ দিবো? যেহেতু আমরা গ্রিডিলি ratio choose করছি এবং গ্রুপের সব ওয়ার্কারকে maximum ratio অনুযায়ী বেতন দিতে হবে তাই ratio কমাইলেও লাভ নাই। বামের ratio অবশ্যই current ratio থেকে কম হবে। তাহলে সবচেয়ে বেশী quality ওয়ালা ওয়ার্কারকেই বাদ দিতে হবে। 
*/