class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        auto counter = [&](string s) -> unordered_map<char,int>{
            unordered_map <char,int> mp;
            for(char c : s)
                mp[c]++;
            return mp;
        };
        unordered_map <char,int> one , two;
        for(string b : words2){
            auto B = counter(b);
            for(auto [c , cnt] : B)  
                one[c] = max(one[c] , cnt);
        }
        vector<string> ans;
        for(string a : words1){
            auto A = counter(a);
            bool ok = true;
            for(auto [c , cnt] : one)   
                if(A[c] < cnt){ 
                    ok = false;
                    break;
                }
            if(ok)
                ans.push_back(a);
        }
        return ans;
    }
};
//** words2 এর প্রতি ওয়ার্ড এ সর্বোচ্চ সংখ্যক ক্যারেকটার এর চাইতে যদি বেশী বা সমান ক্যারেকটার যদি words1 এর কোন ওয়ার্ডে থাকে তাহলে সেটা এন্সার এ যুক্ত হবে **// 