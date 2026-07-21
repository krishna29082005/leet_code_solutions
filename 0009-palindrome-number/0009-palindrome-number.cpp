class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        int ans = 0;
        if(n < 0) return false;
        while(n != 0){
            int temp = n%10;
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && temp > 7)) return false;
            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && temp < -8)) return false;
            ans = ans*10 + temp;
            n = n/10;
        }
        if(ans == x) return true;
        return false;
    }
};