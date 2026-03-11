class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int tgas = 0, tcost = 0;

        for (int i = 0; i < gas.size(); i++) {
            tgas += gas[i];
            tcost += cost[i];
        }

        if (tcost > tgas) return -1;

        int cgas = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {

            cgas += gas[i] - cost[i];

            if (cgas < 0) {
                start = i + 1;
                cgas = 0;
            }
        }

        return start;
    }
};