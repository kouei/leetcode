/******************************************************************************
 * Idea:
 * KMP Algorithm
 * 
 * Let N = the length of the source string
 * Let M = the length of the pattern string
 * Let's also assume N > M
 * 
 * Time:  
 * O(N)
 * 
 * Space:
 * O(M)
 ******************************************************************************/

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
        
        auto i = 1;
        auto j = 0;
        
        while(i < n) {
            if(s[i] == s[j]) {
                next[i] = next[j];
                ++i;
                ++j;
            }
            else {
                next[i] = j;
                while(j != -1 && s[i] != s[j])
                    j = next[j];
                if(j == -1) {
                    ++i;
                    ++j;
                }
            }
        }
        
        return next;
    }
    
    int strStr(const string & s, const string & p) {
        if(p.empty()) return 0;
        
        auto next = get_next(p);
        
        for(auto i : next) cout << i << " ";
        
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
        
        return j == p.size() ? i - p.size() : -1;
    }
};