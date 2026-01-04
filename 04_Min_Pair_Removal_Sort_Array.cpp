// Given an array nums, you can perform the following operation any number of times:

// Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
// Replace the pair with their sum.
// Return the minimum number of operations needed to make the array non-decreasing.

// An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

// Example 1:

// Input: nums = [5,2,3,1]

// Output: 2

// Explanation:

// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.

// Example 2:

// Input: nums = [1,2,2]

// Output: 0

// Explanation:

// The array nums is already sorted.












// My approach but not optimal

class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;

        while (!isNonDecreasing(nums)) {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for (int i = 0; i < nums.size() - 1; i++) {
                pq.push({nums[i] + nums[i + 1], i});
            }

            auto [sum, idx] = pq.top();
            pq.pop();

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            op++;
        }

        return op;
        
    }
};










// Leetcode optimal solution

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
          int ops = 0;

        // Function to check if array is non-decreasing
        auto isSorted = [&]() {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1])
                    return false;
            }
            return true;
        };

        while (!isSorted()) {
            int minSum = INT_MAX;
            int idx = 0;

            // Find adjacent pair with minimum sum
            for (int i = 0; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // Replace the pair with their sum
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);

            ops++;
        }

        return ops;
    }
};