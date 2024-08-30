class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_index;

        for(int i = 0; i < nums.size(); i++)
        {
            int remain = target - nums[i];

            if(value_index.find(remain) != value_index.end())
            return {i, value_index[remain]};

            value_index[nums[i]] = i;
        }
        return {};
    }
};

/*
Brute Force Solution:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        if(nums[i] + nums[j] == target)
        return {i, j};

        return {};
    }
};
*/