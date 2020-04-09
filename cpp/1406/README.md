# 1406. Stone Game III

## Idea （by lee215）
Thanks to lee215 for sharing this elegant solution:  
https://leetcode.com/problems/stone-game-iii/discuss/564260/JavaC%2B%2BPython-DP-O(1)-Space  
  
dp[i] means, if we ignore before A[i],  
what's the highest score that Alex can win over the Bob?  
  
There are three option for Alice to choose.  
Take A[i], win take - dp[i+1]  
Take A[i] + A[i+1], win take - dp[i+2]  
Take A[i] + A[i+1] + A[i+2], win take - dp[i+3]  
dp[i] equals the best outcome of these three solutions.  


## Complexity

Time:  
O(N)

Space:  
O(1)

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
    string stoneGameIII(vector<int>& A) {
        int n = A.size();
        vector<int> dp(4);
        for(auto i = n - 1; i >= 0; --i) {
            dp[i % 4] = INT_MIN;
            for(auto k = 0, take = 0; k < 3 && i + k < n; ++k) {
                take += A[i + k];
                dp[i % 4] = max(dp[i % 4], take - dp[(i + k + 1) % 4]);
            }
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};
```