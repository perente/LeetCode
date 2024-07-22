class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(size_t i = 0; i < words.size(); i++)
        {
            string normal = words[i];
            string reversed;

            for (size_t j = 0; j < normal.size(); j++) {
                reversed.insert(reversed.begin(), normal[j]);
            }

            if(normal == reversed)
            {
                return normal;
            }
        }
        return "";  
    }
};