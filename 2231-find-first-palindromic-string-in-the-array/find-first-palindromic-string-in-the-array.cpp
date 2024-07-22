//Rampia Perente
class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(size_t i = 0; i < words.size(); i++)
        {
            string normal = words[i];
            string reversed = reverse(normal);

            if(normal == reversed)
            {
                return normal;
            }
        }
        return "";  
    }

    string reverse(string& word)
    {
        string reversed;
        for(int i = word.size() - 1; i >= 0; i--)
        {
            reversed += word[i];
        }
        return reversed;
    }
};