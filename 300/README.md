# 300. Longest Increasing Subsequence

## Idea
Dynamic Programming + Binary  Search.  
dp[i] means the smallest tail among all subsequences of length i.  
suppose there are two subsequences of length 4:  
[3,4,5,6] and [4,5,6,7]  
Then dp[4] = 6;  

## Complexity
Let N = the length of the array  
Time: O(NlogN)  
Space: O(N)  

## C++
```C++
static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        dp[0] = INT_MIN;
        
        auto max_len = 0;
        for(auto i : nums) {
            auto start = 0;
            auto end = max_len;
            while(start <= end) {
                auto mid = start + (end - start) / 2;
                if(dp[mid] < i) 
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            dp[start] = i;
            if(start > max_len) max_len += 1;
        }
        
        return max_len;
    }
};
```