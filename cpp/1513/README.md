# 1513. Number of Substrings With Only 1s

## Idea

Find all continuous segments which are made by all 1s.

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
    int numSub(string s) {
        const auto mod = static_cast<int64_t>(1e9 + 7);
        auto n = static_cast<int64_t>(s.size());
        auto res = static_cast<int64_t>(0);
        
        auto j = static_cast<int64_t>(0);
        for(; j < n; ++j) {
            if(s[j] == '1')
                break;
        }
        
        if(j == n)
            return 0;

        auto i = j + 1;
        for(; i < n; ++i) {
            if(s[i] == '1')
                continue;

            auto len = i - j;
            res += (1 + len) * len / 2;
            res %= mod;
            j = i + 1;
        }
        auto len = i - j;
        res += (1 + len) * len / 2;
        res %= mod;
        
        return res;
    }
};
```