//Rampia Perente

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> map;
        for(char c : s)
        map[c]++;

        if(map.empty())
        return true;

        auto it = map.begin();
        int curr = it->second;
        for(auto it = map.begin(); it != map.end(); it++)
        {
            if(curr != it->second)
            return false;
        }
        return true;
    }
};