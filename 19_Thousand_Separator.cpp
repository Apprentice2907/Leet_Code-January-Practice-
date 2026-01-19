// Given an integer n, add a dot (".") as the thousands separator and return it in string format.

// Example 1:

// Input: n = 987
// Output: "987"
// Example 2:

// Input: n = 1234
// Output: "1.234"



// My approach 

class Solution {
public:
    string thousandSeparator(int n) {
        if(n==0) return "0";
        string ans="";
        int count=0;

        while (n > 0) {
            int digit = n % 10;  
            ans = to_string(digit) + ans;
            n = n / 10;
            count++;

            if(count%3==0 && n!=0){
                ans='.'+ans;
            }     
        }
        return ans;
    }
};