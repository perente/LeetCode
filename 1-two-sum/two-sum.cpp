class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int size = nums.size();
        int difference;
        unordered_map<int, int>m;
        for(int i = 0; i < size; i++) {
            difference = target - nums[i];
            if(m.find(difference) != m.end() && m.find(difference)->second != i) {
                ret.push_back(i);
                ret.push_back(m.find(difference)->second);
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};