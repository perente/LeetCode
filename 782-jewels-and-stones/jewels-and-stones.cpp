//Rampia Perente

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> s_count;

        for(char c : stones)
        s_count[c]++;

        int count = 0;
        for(char s : jewels)
        {
            if(s_count.find(s) != s_count.end())
            count += s_count[s];
        }
        return count;
    }
};