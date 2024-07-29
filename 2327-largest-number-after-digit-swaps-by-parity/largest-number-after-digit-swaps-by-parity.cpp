//Rampia Perente

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> odd, even;

        for(char c : s)
        {
            int digit = c - '0';
            if(digit % 2 == 0)
            even.push_back(digit);
            else
            odd.push_back(digit);
        }
        
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());

        string str = "";
        int odd_index = 0, even_index = 0;

        for(char c : s)
        {
            int digit = c - '0';
            if(digit % 2 == 0)
            str += to_string(even[even_index++]);
            else
            str += to_string(odd[odd_index++]);
        }
        return stoi(str);
    }
};