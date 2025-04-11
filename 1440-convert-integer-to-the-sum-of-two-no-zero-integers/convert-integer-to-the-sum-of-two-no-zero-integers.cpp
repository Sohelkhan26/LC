class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto valid = [&](int n){
            while(n > 0){
                if(n % 10 == 0)
                    return false;
                n /= 10;
            }
            return true;
        };
        unordered_set <int> st;
        for(int i = 1 ; i <= n ; i++)
            if(valid(i))
                st.insert(i);
        for(auto it = st.begin() ; it != st.end() ; it++){
            auto b = st.find((n - *it));
            if(b != st.end())
                return {*it , *b};
        }
        return {};
    }
};