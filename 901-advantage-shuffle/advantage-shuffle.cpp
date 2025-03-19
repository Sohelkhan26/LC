class Solution {
public:
    vector<int> advantageCount(vector<int>& a , vector<int>& b) {
        vector <int> ans;
        multiset <int> st(a.begin() , a.end());
        for(int i : b){
            auto it = (*st.rbegin() > i) ? st.upper_bound(i) : st.begin();
            ans.push_back(*it);
            st.erase(it);
        }
        return ans;
    }
};

/*
Straightforward approach. 
For each b[i] , position a[i] that is least greater than b[i](smallest number greater than b[i])
If there is none(all the numbers in a are greater than b[i]) , position smallest a[i].
Reminder : end() iterator points to the element that comes after the last iterator.So, rbegin() is used.
rebegin() points to the last element.
*/