class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> mp;

        for(char c : text) {
            mp[c]++;
        }

        string word = "balloon";
        int count = 0;

        while(true) {

            for(char w : word) {

                if(mp[w] == 0) {
                    return count;
                }

                mp[w]--;
            }

            count++;
        }
    }
};