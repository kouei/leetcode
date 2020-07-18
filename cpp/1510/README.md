# 1510. Stone Game IV

## Idea

Dynamic Programming

## Complexity

Time:  
O(N^1.5)

Space:  
O(N)

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
    bool winnerSquareGame(int n) {
        vector<int> alice_win(n + 1, 0);
        for(auto i = 1; i <= n; ++i) {
            for(auto j = 1; j * j <= i; ++j) {
                if(j * j == i || !alice_win[i - j * j]) {
                    alice_win[i] = 1;
                    break;
                }
            }
        }
        return alice_win[n];
    }
};
```