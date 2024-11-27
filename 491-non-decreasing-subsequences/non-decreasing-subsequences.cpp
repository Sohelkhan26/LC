class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sequence;
        int n = nums.size();
        function<void(int)> dfs = [&](int i) -> void{
            if(sequence.size() > 1)
                ans.push_back(sequence);
            unordered_set <int> vis;
            for(int j = i ; j < n ; j++){ // i == n -> return এই কন্ডিশন দিতে হবে না। ফর লুপের কারনে এমনিতেই রিটার্ন করবে। 
                if((sequence.size() == 0 or sequence.back() <= nums[j]) and not vis.contains(nums[j])){
                    sequence.push_back(nums[j]);
                    dfs(j + 1);
                    sequence.pop_back();
                    vis.insert(nums[j]);
// ৬ , ৭ , ৭ , ৭ এরকম যদি ইনপুট হয়, তাহলে একবার ৭ কারেন্ট সাব সিকোয়েন্সে এড করার পর ৭ মার্ক হয়ে যাবে এবং একই সাবসিকোয়েন্সে দুইবার ৭ এড হবে না। যেহেতু প্রতি ডিএফএস কলে একবার করে সেট ডিক্লেয়ার হচ্ছে তাই এই ভিসিটেড মার্ক করার রেজাল্ট অন্য ডিএফএস কলে রিফ্লেক্ট হবে না। অর্থাৎ অন্য কোন ডিএফএস কলে যদি সাব সিকোয়েন্স ৪ , ৫ হয় সেখানে ৭ এড হতে পারবে , কিন্তু সেটাও প্রথমবারই, এরপরে ভিসিটেড মার্ক হয়ে যাবে , আর পারবে না। 
                }
            }
        }; 
        dfs(0);
        return ans; 
    }
};