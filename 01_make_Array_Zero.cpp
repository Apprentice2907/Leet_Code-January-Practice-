// You are given a non-negative integer array nums. In one operation, you must:

// Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
// Subtract x from every positive element in nums.
// Return the minimum number of operations to make every element in nums equal to 0.

// Example 1:

// Input: nums = [1,5,0,3,5]
// Output: 3
// Explanation:
// In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
// In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
// In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
// Example 2:

// Input: nums = [0]
// Output: 0
// Explanation: Each element in nums is already 0 so no operations are needed.









// My solution and optimal and correct approach too 

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> min;
        for (int num:nums){
            if (num>0){
                min.push(num);
            }
        }
        int op=0;
        int value=0;
        while(!min.empty()){
            int small=min.top();
            min.pop();
            small-=value;
            if(small==0){
                continue;
            }
            op+=1;
            value+=small;
        }
        return op;
    }
};










// Mathematical solution but not optimal and also not correct logic

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> min;
        for (int num:nums){
            if (num>0){
                min.push(num);
            }
        }
        if(min.empty()) return 0;
        int op=0;
        int prev=0;
        while(!min.empty()){
            int curr=min.top();
            min.pop();
            if(curr>prev){
                op+=1;
                prev=curr;
            }
        }
        return op;
    }
};









// Leetcode optimal solution but not correct logic

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uniquePositives;
        
        for (int num : nums) {
            if (num > 0) {
                uniquePositives.insert(num);
            }
        }
        
        return uniquePositives.size();
    }
};