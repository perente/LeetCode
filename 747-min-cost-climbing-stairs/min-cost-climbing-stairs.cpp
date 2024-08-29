//Rampia Perente

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = cost.size();

        vector<int> min_cost(x);
        min_cost[0] = cost[0];
        min_cost[1] = cost[1];

        for(int i = 2; i <= x - 1; i++)
        min_cost[i] = min(min_cost[i - 1] + cost[i], min_cost[i - 2] + cost[i]);

        return min(min_cost[x - 1], min_cost[x - 2]);
    }
};