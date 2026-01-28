// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

 

// Example 1:

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]
 






// My approach but not optimal 

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) return a > b;
            return freq[a] < freq[b];
        });

        return nums;
    }
};









// Leetcode optimal solution

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        for(auto j:nums){
            m[j]++;
        } 
        vector<pair<int,int> > t;
        for(auto j:m){
            t.push_back({j.second,j.first});

        }
        sort(t.begin(),t.end(),[](auto &a,auto &b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            else{
                return a.first<b.first;
            }
        });
        vector<int> ans;
        for(auto j:t){
            int b=j.first;
            while(j.first--){
                ans.push_back(j.second);
            }
        }
        return ans;
    }
};