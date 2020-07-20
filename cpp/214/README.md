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
static int io_accelerator = [](){
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
        
        int i = 0;
        int j = -1;
        
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
        string p = s;
        vector<int> next = get_next(p);
        reverse(s.begin(), s.end());
        
        int i = 0;
        int j = 0;
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
        for(int i = 0; i < s.size() - j; ++i)
            res += s[i];
        res += p;
        return res;
    }
};
```