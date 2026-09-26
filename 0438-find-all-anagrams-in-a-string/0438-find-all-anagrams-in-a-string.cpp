class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char c : p) {
            pFreq[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++) {

            windowFreq[s[right] - 'a']++;

            if (right - left + 1 > p.size()) {
                windowFreq[s[left] - 'a']--;
                left++;
            }

            if (windowFreq == pFreq) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};