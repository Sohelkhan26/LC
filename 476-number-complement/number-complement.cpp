class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while(num & mask) mask <<= 1;
        return ~num ^ mask;
    }
};

/*
প্রথম দেখায় মনে হতে পারে এনসার হবে ~num আসলে এনসার এটাই কিন্তু num এর leading zero গুলা ঝামেলা করে। তাই ~৫ = -৬ হয়ে যায়। তাহলে leading zero গুলা eliminate করতে হবে। while(num & mask) mask <<= 1
এই কাজটাই করে। যতক্ষন পর্যন্ত mask এর যেকোন সেট বিট num এর কোন বিট এর সাথে result উতপন্ন করবে ততক্ষন Left Shift করতে হবে। তাহলে লাস্ট সেট বিটের পরে mask এর সব ১১১১ থাকবে। ~num  হলো আসল এনসার 
এটার সাথে ^ mask করে leading zero eliminate করা হইছে। 
num          = 00000101
mask         = 11111000 (After while loop)
~mask & ~num = 00000010
*/