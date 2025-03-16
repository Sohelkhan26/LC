class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack <int> st;
        for(char c : s){
            if(c == '('){
                if(st.empty() or st.top() == 2)
                    st.push(2);
                else{
                    st.pop();
                    ans++;
                    st.push(2);
                }
            }else{
                if(st.empty()){
                    ans += 1; //need to insert ( before
                    st.push(1);
                }else if(st.top() == 2){
                    st.pop();
                    st.push(1);
                }else{
                    st.pop();
                }
            }
        }
        while(not st.empty())
            ans += st.top() , st.pop();
        return ans;
    }
};