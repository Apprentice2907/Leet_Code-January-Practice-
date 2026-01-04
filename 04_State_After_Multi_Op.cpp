// You are given an integer array nums, an integer k, and an integer multiplier.

// You need to perform k operations on nums. In each operation:

// Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums after performing all k operations.

// Example 1:

// Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

// Output: [8,4,6,5,6]

// Explanation:

// Operation	Result
// After operation 1	[2, 2, 3, 5, 6]
// After operation 2	[4, 2, 3, 5, 6]
// After operation 3	[4, 4, 3, 5, 6]
// After operation 4	[4, 4, 6, 5, 6]
// After operation 5	[8, 4, 6, 5, 6]
// Example 2:

// Input: nums = [1,2], k = 3, multiplier = 4

// Output: [16,8]

// Explanation:

// Operation	Result
// After operation 1	[4, 2]
// After operation 2	[4, 8]
// After operation 3	[16, 8]







// My solution but not optimal

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            priority_queue<pair<int, int>> pq;
            for (auto &it : freq) {
                pq.push({it.second, it.first});
            }

            int sum = 0;
            int count = 0;

            while (!pq.empty() && count < x) {
                auto [f, val] = pq.top();
                pq.pop();
                sum += f * val;
                count++;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};










// Leetcode optimal solution

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int cnts[51]{};
        vector<set<int, greater<int>>> buckets(51);
        int n = nums.size();
        vector<int> answer(n - k + 1);

        auto getXSum = [&](int x) {
            int x_sum = 0;
            for (int i = 50; i >= 0 && x > 0; i--) {
                for (int num: buckets[i]) {
                    x_sum += i * num;
                    if (--x == 0) {
                        break;
                    }
                }
            }  
            return x_sum;
        };

        for (int i = 0; i < k; i++) {
            int num = nums[i];
            if (cnts[num] > 0) buckets[cnts[num]].erase(num);
            buckets[++cnts[num]].insert(num);
        }

        for (int i = k; i < n; i++) {
            answer[i - k] = getXSum(x);
            buckets[cnts[nums[i - k]]--].erase(nums[i - k]);
            buckets[cnts[nums[i - k]]].insert(nums[i - k]);
            if (cnts[nums[i]] > 0) buckets[cnts[nums[i]]].erase(nums[i]);
            buckets[++cnts[nums[i]]].insert(nums[i]);
        }
        answer[n - k] = getXSum(x);
        return answer;
    }
};