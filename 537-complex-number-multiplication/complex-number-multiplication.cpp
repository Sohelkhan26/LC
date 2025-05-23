class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto parse = [&](string s){
            int i = s.find('+');
            int real = stoi(s.substr(0 , i));
            int imag = stoi(s.substr(i + 1 , s.size() - i - 2)); // i - 1 for substring up until i and extra -1 for 'i' at the end.
            return complex<int> (real , imag);
        };
        complex <int> a = parse(num1) , b = parse(num2) , ans = a * b;
        return to_string(real(ans)) + "+" + to_string(imag(ans)) + "i";
    }
};