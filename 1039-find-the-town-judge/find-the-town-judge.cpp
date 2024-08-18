//Rampia Perente

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_balance(n + 1, 0);

        if(n == 1)
        return 1;

        int size = trust.size();
        for(int i = 0; i < size; i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];
            trust_balance[a]--;
            trust_balance[b]++;
        }

        for(int j = 1; j <= n; j++)
        {
            if(trust_balance[j] == n - 1)
            return j;
        }

        return -1;
    }
};