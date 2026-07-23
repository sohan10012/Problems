class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> seen;

        for (char c : magazine) {
            seen[c]++;
        }

        for (char c : ransomNote) {
            if (seen[c] == 0)
                return false;

            seen[c]--;
        }

        return true;
    }
};