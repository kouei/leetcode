# 214. Shortest Palindrome

## Idea
KMP Algorithm.  
Find the longest prefix of s where it is also a palindrome.  
Then add the rest suffix (in reverse order) to the beginning of s.  

## Complexity
Let N be the length of s.  
Time: O(N)  
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
    
    vector<int> get_next(const string & s) {
        int n = s.size();
        vector<int> next(n);
        next[0] = -1;
        
        auto i = 0;
        auto j = -1;
        
        while(i + 1 < n) {
            if(j == -1 || s[i] == s[j]) {
                ++i;
                ++j;
                next[i] = s[i] == s[j] ?  next[j] : j;
            }
            else j = next[j];
        }
        
        return next;
    }

    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        auto p = s;
        auto next = get_next(p);
        reverse(s.begin(), s.end());
        
        auto i = 0;
        auto j = 0;
        for(; i < s.size() && j < p.size();) {
            if(s[i] == p[j]) {
                ++i;
                ++j;
            }
            else if(next[j] == -1) {
                ++i;
                j = 0;
            }
            else j = next[j];
        }
        
        string res;
        for(auto i = 0; i < s.size() - j; ++i)
            res += s[i];
        res += p;
        return res;
    }
};
```