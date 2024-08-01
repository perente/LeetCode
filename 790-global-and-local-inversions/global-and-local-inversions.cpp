
class Solution {
public:
    // Function to merge two halves and count inversions
    long long mergeAndCount(vector<int>& nums, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        vector<int> leftPart(n1);
        vector<int> rightPart(n2);

        for (int i = 0; i < n1; i++)
            leftPart[i] = nums[left + i];
        for (int j = 0; j < n2; j++)
            rightPart[j] = nums[middle + 1 + j];

        int i = 0, j = 0, k = left;
        long long inversions = 0;

        while (i < n1 && j < n2) {
            if (leftPart[i] <= rightPart[j]) {
                nums[k++] = leftPart[i++];
            } else {
                nums[k++] = rightPart[j++];
                inversions += (n1 - i); // Count inversions
            }
        }

        while (i < n1) {
            nums[k++] = leftPart[i++];
        }

        while (j < n2) {
            nums[k++] = rightPart[j++];
        }

        return inversions;
    }

    // Recursive function to sort and count inversions
    long long mergeSortAndCount(vector<int>& nums, int left, int right) {
        long long inversions = 0;
        if (left < right) {
            int middle = left + (right - left) / 2;
            
            inversions += mergeSortAndCount(nums, left, middle);
            inversions += mergeSortAndCount(nums, middle + 1, right);
            inversions += mergeAndCount(nums, left, middle, right);
        }
        return inversions;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Count local inversions
        int localInversions = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                localInversions++;
            }
        }

        // Count global inversions
        long long globalInversions = mergeSortAndCount(nums, 0, n - 1);
        
        return localInversions == globalInversions;
    }
};
