# 91. Decode Ways

## Idea

Simple dynamic programming.  
dp[i] means how many ways to decode the suffix string starts at position i.  
dp[i] = is_able_to_decode_as_single_digit(s[i]) * dp[i + 1] + is_able_to_decode_as_double_digit(s[i], s[i + 1]) * dp[i + 2];  

Modulo trick is used to make the space cost constant.  

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
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(3);
        for(auto i = n - 1; i >= 0; --i) {
            if(s[i] == '0') {
                dp[i % 3] = 0;
            } else if(s[i] == '1') {
                if(i + 1 == n) {
                    dp[i % 3] = 1;
                } else {
                    dp[i % 3] = dp[(i + 1) % 3] + (i + 2 == n ? 1 : dp[(i + 2) % 3]);
                }
            } else if(s[i] == '2') {
                if(i + 1 == n) {
                    dp[i % 3] = 1;
                } else if(s[i + 1] <= '6') {
                    dp[i % 3] = dp[(i + 1) % 3] + (i + 2 == n ? 1 : dp[(i + 2) % 3]);
                } else {
                    dp[i % 3] = dp[(i + 1) % 3];
                }
            } else {
                dp[i % 3] = (i + 1 == n ? 1 : dp[(i + 1) % 3]);
            }
        }
        
        return dp[0];
    }
};
```