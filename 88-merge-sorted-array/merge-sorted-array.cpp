//Rampia Perente

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> final(m + n);

        int p1 = 0;
        int p2 = 0;
        int pf = 0;

        while(p1 < m && p2 < n)
        {
            if(nums1[p1] < nums2[p2])
            final[pf++] = nums1[p1++];
            else
            final[pf++] = nums2[p2++];
        }

        while(p1 < m)
        final[pf++] = nums1[p1++];

        while(p2 < n)
        final[pf++] = nums2[p2++];

        for(int i = 0; i < m + n; i++)
        nums1[i] = final[i];
    }
};