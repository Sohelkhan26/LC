/*
প্রবলেমটা নতুন ভাবে চিন্তা করা যাক। এমন একটা contiguous subarray select করতে হবে যাতে ঐ সাবএরের এলিমেন্ট গুলা বাদ দিলে বাকি যেসব এলিমেন্ট থাকে সেগুলাতে অন্তত k ক্যারেকটার থাকবে। এই সাব এরের লেংথ ম্যাক্সিমাইজ করতে পারলেই এনসার বের হবে। অর্থাৎ ম্যাক্সিমাম কত লেংথ এর সাব এরে ডিলেট করা যাবে যাতে বাকি সাবএরেতে ক্যারেকটার সংখ্যা অন্তত k থাকে। 
*/
class Solution {
public:
    int takeCharacters(string s, int k) {
        int count[3] = {0} , n = s.size() , ans = -1;
        for(char c : s)
            count[c - 'a']++;
        if(*min_element(count , count + 3) < k)
            return -1;
        // এখন পুরা string ই ভ্যালিড। সব ক্যারেকটার (a/b/c) অন্তত k বার আছে। 
        for(int left = 0 , right = 0 ; right < n ; right++){
            count[s[right] - 'a']--;
            while(*min_element(count , count + 3) < k)
                count[s[left++] - 'a']++;
            ans = max(ans , right - left + 1);
        }
        return n - ans;
    }
};