// Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
// A subarray is a contiguous subsequence of the array.

// Example 1:

// Input: arr = [1,4,2,5,3]
// Output: 58
// Explanation: The odd-length subarrays of arr and their sums are:
// [1] = 1
// [4] = 4
// [2] = 2
// [5] = 5
// [3] = 3
// [1,4,2] = 7
// [4,2,5] = 11
// [2,5,3] = 10
// [1,4,2,5,3] = 15
// If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
// Example 2:

// Input: arr = [1,2]
// Output: 3
// Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
// Example 3:

// Input: arr = [10,11,12]
// Output: 66









// My approach 

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for (int start = 0; start < n; start++) {
            int currSum = 0;
            for (int end = start; end < n; end++) {
                currSum += arr[end];
                int length = end - start + 1;

                if (length % 2 == 1) {
                    totalSum += currSum;
                }
            }
        }

        return totalSum;
    }
};






// Leetcode optimal solution

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),sum=0,tot,odd;
        for (int i=0;i<n;i++)
    {
        tot=(i+1)*(n-i);
        odd=(tot+1)/2;
        sum+=arr[i]*odd;
    }
return sum;
    }
};