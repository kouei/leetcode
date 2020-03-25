# 407. Trapping Rain Water II

## Idea
Search from edge to center. 
Keep updating the outline of the wall.
Below is a nice visualization of this algorithm.
https://www.youtube.com/watch?v=cJayBq38VYw

## Complexity
Suppose the grid has R rows and C columns.

Time:  
O(RClog(RC)) since every cell will enter and leave the heap exactly once.

Space:  
O(RC) for the heap and the visited array.

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
    int trapRainWater(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<vector<int>> visited(R, vector<int>(C));

        auto res = 0;
        auto max_val = INT_MIN;

        for(auto r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if(!(r == 0 || r + 1 == R || c == 0 || c + 1 == C)) continue;
                heap.push({grid[r][c], r * C + c});
                visited[r][c] = 1;
            }
        }
        
        vector<vector<int>> diff{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!heap.empty()) {
            auto val = heap.top(); 
            heap.pop();

            auto height = val.first;
            auto r = val.second / C;
            auto c = val.second % C;
            max_val = max(max_val, height);

            for(auto & d : diff) {
                auto r2 = r + d[0];
                auto c2 = c + d[1];

                if(!(0 <= r2 && r2 < R && 0 <= c2 && c2 < C)) continue;

                if(visited[r2][c2]) continue;

                visited[r2][c2] = 1;

                if(grid[r2][c2] < max_val) res += max_val - grid[r2][c2];

                heap.push({grid[r2][c2], r2 * C + c2});
            }
        }
        return res;
    }
};
```
