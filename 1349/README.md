# 1349. Maximum Students Taking Exam

## Idea
This problem has two solutions
1. Bitmask Dynamic Programming
2. Hungarian Algorithm (Optimal)

### Bitmask Dynamic Programming
dp[r][mask] means the max possible number of students for the first r rows  
when the r th row's state is mask.  
dp[r][mask] = argmax(previous_mask) dp[r - 1][previous_mask] + ones(mask)  
where ones(x) counts the number of ones in x, and previous_mask is  
the mask of the previous row;  

### Complexity
Let R = number of rows
Let C = number of cols

Time: O(R * 2^(2C))  
Space: O(2^C)

### C++
```C++
static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int R = seats.size();
        int C = seats[0].size();
        
        vector<int> valid_states;
        for (auto r = 0; r < R; ++r) {
            auto state = 0;
            for (auto c = 0; c < C; ++c) 
                state = (state << 1) + (seats[r][c] == '.');
            valid_states.push_back(state);
        }
		
        vector<int> cur(1 << C, -1);
        vector<int> last(1 << C, -1);
        
        for (auto r = 0; r < R; ++r) {
            
            swap(cur, last);
            
            auto valid = valid_states[r];
            
            // current row state
            for (auto c = 0; c < (1 << C); ++c) {

                // current state is not a subset of valid state.
                if((c & valid) != c)
                    continue;

                // in the same row, adjacent seats cannot be taken simultaneously.
                if(c & (c >> 1))
                    continue;
                    
                // solve the first row
                if(r == 0) {
                    cur[c] = __builtin_popcount(c);
                    continue;
                }

                // solve other rows
                // previous row state
                for (auto k = 0; k < (1 << C); ++k) {
                    
                    // conflict with the left front seat
                    if(c & (k >> 1))
                        continue;
                    
                    // conflict with the right front seat
                    if((c >> 1) & k)
                        continue;
                        
                    // previous row state infeasible
                    if(last[k] == -1)
                        continue;
                    
                    cur[c] = max(cur[c], last[k] + __builtin_popcount(c));
                }
            }
        }
        
        return *max_element(cur.begin(), cur.end());
    }
};
```

### Hungarian Algorithm (Optimal)
Seats on even columns and seats on odd columns form a bipartite graph.  
Using Hungarian Algorithm to find the Maximum Matching for this graph.  
Then, the answer is: [total # of seats] - [# of edges in the Maximum ching].  
The answer is also known as Maximum Independent Set.  

### Complexity
Let R = number of rows  
Let C = number of cols  
Time: O(R^2 * C^2)  
Space: O(RC)

### C++
```C++
static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:

    vector<vector<vector<int>>> matching;
    vector<vector<char>> seats;
    int R, C;
    
    bool dfs(const vector<int> & node, vector<vector<int>> & seen) {
        auto r = node[0];
        auto c = node[1];
        
        vector<vector<int>> delta{{-1,-1},{0,-1},{0,+1},{-1,+1},{+1,-1},{+1,+1}};
        for(auto & d : delta) {
            auto nr = r + d[0];
            auto nc = c + d[1];
            
            if(0 <= nr && nr < R && 
               0 <= nc && nc < C && 
               seats[nr][nc] == '.' && 
               !seen[nr][nc]) {
                
                seen[nr][nc] = true;
                if(matching[nr][nc].empty() || dfs(matching[nr][nc], seen)) {
                    matching[nr][nc] = {r, c};
                    return true;
                }
            }
        }
        return false;
    }

    int Hungarian() {
        auto res = 0;
        for(auto c = 0; c < C; c += 2) {
            for(auto r = 0; r < R; ++r) {
                if(seats[r][c] != '.') 
                    continue;
                auto seen = vector<vector<int>>(R, vector<int>(C, false));
                res += dfs({r, c}, seen);
            }
        }
        return res;
    }
    
    int maxStudents(vector<vector<char>>& _seats) {
        swap(seats, _seats);
        R = seats.size();
        C = seats[0].size();
        
        matching = vector<vector<vector<int>>>(R, vector<vector<int>>(C));
        
        
        auto res = Hungarian();
                
        auto count = 0;
        for(auto r = 0; r < R; ++r)
            for(auto c = 0; c < C; ++c)
                count += seats[r][c] == '.';
        return count - res;
    }
};
```