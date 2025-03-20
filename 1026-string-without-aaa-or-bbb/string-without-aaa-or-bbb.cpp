class Solution {
public:
    string strWithout3a3b(int a, int b , char aa = 'a' , char bb = 'b' , string ans = "") {
        if(b > a)
            return strWithout3a3b(b , a , bb , aa);
        while(a-- > 0){
            ans.push_back(aa);
            if(a > b) // we took care of b > a earlier. Only one case possible where if condition is not fulfilled: a == b, then it should be like this : abab / baba
                ans.push_back(aa) , a--;
            if(b-- > 0)
                ans.push_back(bb);
        }
        return ans;
    }
};