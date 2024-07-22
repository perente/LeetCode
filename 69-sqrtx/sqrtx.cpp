//Rampia Perente
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
        return 0;

        int left = 1;
        int right = x;
        int sqrtx;

        while(left <= right)
        {
            int middle = left + (right - left)/2;
            if(middle <= x/middle)
            {
                sqrtx = middle;
                left = middle + 1;
            } else
            right = middle - 1;
        }
        return sqrtx;
    }
};