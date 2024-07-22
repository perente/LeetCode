class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right)
        {
            int middle = left + (right - left)/2;
            if (check(piles, h, middle))
            right = middle;  
            else 
            left = middle + 1;  
        }
        return left;
    }

    bool check(vector<int>& piles, int h, int k)
    {
        int hours = 0;
        for(int pile:piles)
        {
            hours += (pile + k - 1)/k;
        }
        return hours <= h;
    }
};