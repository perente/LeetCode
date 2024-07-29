//Rampia Perente

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int good_pairs = 0;

        for(int i : nums)
        good_pairs += freqMap[i]++;

        return good_pairs;
    }
};