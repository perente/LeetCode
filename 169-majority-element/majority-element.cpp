//Rampia Perente

class Solution {
public:
    void merge(vector<int>& nums, int left, int middle, int right){
        int nums1 = middle - left + 1;
        int nums2 = right - middle;

        vector<int> left_sub(nums1);
        vector<int> right_sub(nums2);

        for(int i = 0; i < nums1; i++)
        left_sub[i] = nums[left + i];
        for(int j = 0; j < nums2; j++)
        right_sub[j] = nums[middle + 1 + j];

        int p1 = 0;
        int p2 = 0;
        int pf = left;

        while(p1 < nums1 && p2 < nums2)
        {
            if(left_sub[p1] < right_sub[p2])
            nums[pf++] = left_sub[p1++];
            else
            nums[pf++] = right_sub[p2++];
        }

        while(p1 < nums1)
        nums[pf++] = left_sub[p1++];

        while(p2 < nums2)
        nums[pf++] = right_sub[p2++];
    }

    void merge_sort(vector<int>& nums, int left, int right){
        if(left >= right)
        return;
        int middle = left + (right - left) / 2;

        merge_sort(nums, left, middle);
        merge_sort(nums, middle + 1, right);
        merge(nums, left, middle, right);
    }

    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       merge_sort(nums, 0, n - 1);
       return nums[n / 2];
    }
};