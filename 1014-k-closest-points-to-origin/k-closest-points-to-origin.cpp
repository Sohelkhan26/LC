class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin() , points.end() , [&](auto a , auto b){
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }); 
// দুইটা পয়েন্টের মধ্যে কম্পেয়ার করে সর্ট করা হবে। যদি দুই নাম্বার পয়েন্ট এর দূরত্ব বেশী হয় তাহলে সেটা swap হয়ে পরে চলে যাবে। comparator function true return করলে swap হয়। 
        vector<vector<int>> ans;
        for(int i = 0 ; i < k ; i++)
            ans.push_back(points[i]);
        return ans;
    }
};