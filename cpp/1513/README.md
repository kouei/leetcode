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
static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numSub(string s) {
        const int64_t mod = static_cast<int64_t>(1e9 + 7);
        int64_t n = static_cast<int64_t>(s.size());
        int64_t res = static_cast<int64_t>(0);
        
        int64_t j = static_cast<int64_t>(0);
        for(; j < n; ++j) {
            if(s[j] == '1')
                break;
        }
        
        if(j == n)
            return 0;

        int64_t i = j + 1;
        for(; i < n; ++i) {
            if(s[i] == '1')
                continue;

            int64_t len = i - j;
            res += (1 + len) * len / 2;
            res %= mod;
            j = i + 1;
        }
        int64_t len = i - j;
        res += (1 + len) * len / 2;
        res %= mod;
        
        return res;
    }
};
```