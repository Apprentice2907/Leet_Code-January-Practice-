// Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: s = "aa"
// Output: 0
// Explanation: The optimal substring here is an empty substring between the two 'a's.
// Example 2:

// Input: s = "abca"
// Output: 2
// Explanation: The optimal substring here is "bc".
// Example 3:

// Input: s = "cbzxy"
// Output: -1
// Explanation: There are no characters that appear twice in s.






// My approach but little bit google help

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxl = -1;

        for (char ch : s) {
            size_t first = s.find(ch);
            size_t last  = s.rfind(ch);

            if (first != last) {
                int len = (int)last - (int)first - 1;
                maxl = max(maxl, len);
            }
        }

        return maxl;
    }
};
