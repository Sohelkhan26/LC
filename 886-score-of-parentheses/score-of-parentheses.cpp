class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        int score = 0;
        for(char &c : s){
            if(c == '(')
                st.push(score) , score = 0;
            else{
                score = st.top() + (score == 0 ? 1 : score * 2);
                st.pop();
            }
        }
        return score;
    }
};

/*
if c == ')', 
End of layer: ((())) i.e: the last ). st.top() indicates the score of the current layer.
if score == 0 then there was just one ( before. Add 1 to score, otherwise *2.
if c == '(' opening of new layer
*/