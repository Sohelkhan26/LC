class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> bin;
        for (int num : nums) {
            string s = bitset <8> (num).to_string(); 
            bin.push_back(s.substr(s.find('1'))); // bitset to_string has extra 0b prefix and leading zero, we don't want that
        }
/*
"11" + "10" → "1110" (binary 14)
"10" + "11" → "1011" (binary 11)
So "11" should come before "10".
*/
        sort(bin.begin(), bin.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string result;
        for (const string& s : bin) {
            result += s;
        }
        return stoi(result , nullptr , 2); // third parameter is base , result is in binary so 2
    }
};
