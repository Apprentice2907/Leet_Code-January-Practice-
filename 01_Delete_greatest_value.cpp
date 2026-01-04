// Perform the following operation until grid becomes empty:

// Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
// Add the maximum of deleted elements to the answer.
// Note that the number of columns decreases by one after each operation.

// Return the answer after performing the operations described above.

// Example 1:


// Input: grid = [[1,2,4],[3,3,1]]
// Output: 8
// Explanation: The diagram above shows the removed values in each step.
// - In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can remove any of them). We add 4 to the answer.
// - In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
// - In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
// The final answer = 4 + 3 + 1 = 8.
// Example 2:


// Input: grid = [[10]]
// Output: 10
// Explanation: The diagram above shows the removed values in each step.
// - In the first operation, we remove 10 from the first row. We add 10 to the answer.
// The final answer = 10.








// My solution and optimal too using google for syntax related help

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<priority_queue<int>> q(n);
        for(int i=0;i<n;i++){
            for(int num:grid[i]){
                q[i].push(num);
            }
        }
        for(int col=0;col<m;col++){
            int maxv=0;
            for(int i=0;i<n;i++){
                int rem=q[i].top();
                q[i].pop();
                maxv=max(maxv,rem);
            }
            ans+=maxv;
        }

        return ans;
    }
};

