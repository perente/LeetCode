//Rampia Perente
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while(left < right)
        {
            int middle = left + (right - left)/2;
            if(arr[middle] < arr[middle + 1])
            left = middle + 1;
            else
            right = middle;
        }
        return left;
    }
};