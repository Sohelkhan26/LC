class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set <int> all , prev;
        for(const int &i : arr){
            unordered_set <int> curr = {i};
            for(const int &p : prev)
                curr.insert(i | p);
            all.insert(curr.begin() , curr.end());
            swap(curr , prev);
        }
        return all.size();
    }
};