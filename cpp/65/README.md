# 65. Valid Number

## Idea

DFA (Deterministic Finite Automaton) is the most straight forward solution.  
The state transition table is as follows:  

(Valid states are marked by **√**.)

| State | Example | [0-9] | +/- | e | . |
| ----- | ------- | ----- | --- | - | - |
|0||1|2|End|3|
|**1√**|3|1|End|4|5|
|2|-|1|End|End|3|
|3|.|5|End|End|End|
|4|3e|6|7|End|End|
|**5√**|3.|5|End|4|End|
|**6√**|3e3|6|End|End|End|
|7|3e-|6|End|End|End|
|End|/|/|/|/|/|

## Complexity
Time: O(N)  
Space: O(1)

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
    
    void trim(string & s) {
        int n = s.size();
        auto i = 0;
        for(; i < n && s[i] == ' '; ++i) {}
        
        auto j = n - 1;
        for(; j >= 0 && s[j] == ' '; --j) {}
        
        auto pos = 0;
        auto start = max(0, i);
        auto end = min(n - 1, j);
        for(auto k = start; k <= end; ++k)
            s[pos++] = s[k];
        s.resize(pos);
    }
    
    bool isNumber(string s) {
        trim(s);
        auto state = 0;
        
        for(auto ch : s) {
            if('0' <= ch && ch <= '9') {
                switch(state) {
                    case 0:
                    case 1:
                    case 2:
                        state = 1;
                        break;
                    case 3:
                    case 5:
                        state = 5;
                        break;
                    case 4:
                    case 6:
                    case 7:
                        state = 6;
                        break;
                }
            }
            else if(ch == '+' || ch == '-') {
                switch(state) {
                    case 0:
                        state = 2;
                        break;
                    case 4:
                        state = 7;
                        break;
                    default:
                        return false;
                }
            }
            else if(ch == 'e') {
                switch(state) {
                    case 1:
                    case 5:
                        state = 4;
                        break;
                    default:
                        return false;
                }
            }
            else if(ch == '.') {
                switch(state) {
                    case 0:
                    case 2:
                        state = 3;
                        break;
                    case 1:
                        state = 5;
                        break;
                    default:
                        return false;
                }
            }
            else
                return false;
        }
        
        return state == 1 || state == 5 || state == 6;
    }
};
```