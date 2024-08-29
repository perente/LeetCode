//Rampia Perente

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> few(amount + 1, amount + 1);
        few[0] = 0;
        
        for(int i = 0; i <= amount; i++)
        for(int j : coins)
        if(i - j >= 0)
        few[i] = min(few[i], few[i - j] + 1);

        return few[amount] > amount ? -1 : few[amount];
    }
};