class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x != 0 && x % 10 == 0) 
        {
            return false;
        }
        
        int l_r = x;
        int r_l = 0;
        while(x > 0)
        {
            int digit = x % 10;

            if (r_l > (numeric_limits<int>::max() - digit) / 10)
            return false;

            r_l = digit + r_l*10;
            x /= 10; 
        }

        return r_l == l_r;
    }
};