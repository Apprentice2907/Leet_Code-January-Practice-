// Given an integer array arr, return the mean of the remaining integers after removing the smallest 5% and the largest 5% of the elements.

// Answers within 10-5 of the actual answer will be considered accepted.

// Example 1:

// Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
// Output: 2.00000
// Explanation: After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
// Example 2:

// Input: arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
// Output: 4.00000
// Example 3:

// Input: arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
// Output: 4.77778









// my logic but AI coded

class Solution {
public:
    double trimMean(vector<int>& arr) {

        int n = arr.size();
        int k = (int)(0.05 * n);   

        sort(arr.begin(), arr.end());

        arr.erase(arr.begin(), arr.begin() + k);

        arr.erase(arr.end() - k, arr.end());

        if (arr.empty()) {
            return 0;
        }

        double sum = 0;
        for (int x : arr)
            sum += x;

        double mean = sum / arr.size();

        return mean;
    }
};








// Leetcode optimal solution

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int t=0;
        int n=arr.size();
        t=(int)(n*0.05);
        int s=0;
        for(int i=0;i<t;i++)
        s+=arr[i];
        for(int i=n-1;i>=n-t;i--)
        s+=arr[i];
        return ((accumulate(arr.begin(),arr.end(),0)-s)/(1.0*(n-(2.0*t))));
    }
};