# 1392. Longest Happy Prefix

## Idea
KMP Algorithm.

## Complexity
Let N = the length of the string.

Time:  
O(N)

Space:  
O(N)

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
        int j = - 1;
        while(i + 1 < n) {
            if(j == -1 || s[i] == s[j]) {
                ++i;
                ++j;
                next[i] = s[i] == s[j] ? next[j] : j;
            }
            else j = next[j];
        }
        return next;
    }
    
    string longestPrefix(const string & s) {
        vector<int> next = get_next(s);
        
        int n = s.size();
        int i = 1;
        int j = 0;
        while(i < n) {
            if(s[i] == s[j]) {
                ++i;
                ++j;
            }
            else {
                j = next[j];
                if(j == -1) {
                    ++j;
                    ++i;
                }
            }
        }
        
        return s.substr(0, j);
    }
};
```