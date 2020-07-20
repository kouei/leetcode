# 300. Longest Increasing Subsequence

## Idea
Dynamic Programming + Binary  Search.  
dp[i] means the smallest tail among all subsequences of length i + 1.  
suppose there are two subsequences of length 4:  
[3,4,5,6] and [4,5,6,7]  
Then dp[3] = 6.  

Initially, all dp[i] == INF.
Another observation is that dp is non-decreasing.

## Complexity
Let N = the length of the array  
Time: O(NlogN)  
Space: O(N)  

## C++
```C++
static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> dp(n, INT_MAX);
        
        for(int i = 0; i < n; ++i) {
            *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
        
        return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    }
};
```