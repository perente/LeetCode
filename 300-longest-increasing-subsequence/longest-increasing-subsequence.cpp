//Rampia Perente

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int x = nums.size();
        if (x == 0)
        return 0;

        vector<int> subsequ(x, 1);

        for(int i = 1; i < x; i++)
        for(int j = 0; j < i; j++)
        if(nums[i] > nums[j])
        subsequ[i] = max(subsequ[i], subsequ[j] + 1);

        return *max_element(subsequ.begin(), subsequ.end());
    }
};