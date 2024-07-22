class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        return "";

        string prefix;
        for(size_t i = 0; i < strs[0].size(); i++)
        {
            char curr = strs[0][i];
            for(size_t j = 1; j < strs.size(); j++)
            {
                if(strs[j][i] != curr || i >= strs[j].size())
                return prefix;
            }
            prefix += curr;
        }
        return prefix;
    }
};