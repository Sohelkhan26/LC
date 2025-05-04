class Solution {
public:
    int minimumBuckets(string ham) {
        int n = ham.size() , ans = 0;
        auto oneBucket = [&](){
            int one = 0;
            for(int i = 0 ; i < n ; i++){
                if(ham[i] == 'H' and i + 1 < n and ham[i + 1] == '.' and i + 2 < n and ham[i + 2] == 'H')
                    one++ , i += 2;
            }
            return one;
        };
        if(ham == "H" or ham.starts_with("HH") or ham.ends_with("HH") or ham.find("HHH") != -1)
            return -1;
        return count(ham.begin() , ham.end() , 'H') - oneBucket();
    }
};