class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        int len = 0;
        bool odd = false;

        for (auto &it : freq) {
            if (it.second % 2 == 0) {
                len += it.second;
            } else {
                len += it.second - 1;
                odd = true;
            }
        }

        if (odd)
            len++;

        return len;
    }
};