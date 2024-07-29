//Rampia Perente

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n);

        for(int i = 0; i < n; i++)
        friends[i] = i + 1;

        int curr_index = 0;
        while(friends.size() > 1)
        {   
            curr_index = (curr_index + k - 1) % friends.size();
            friends.erase(friends.begin() + curr_index);
        }
        return friends[0];
    }
};