# 1499. Max Value of Equation

## Idea

Use a deque.
Note that i < j means |xi - xj| will always be -xi + xj.

## Complexity

Time:  
O(N)

Space:  
O(N)

## C++
static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        auto res = INT_MIN;
        deque<pair<int, int>> q;
        for(auto & p : points) {
            auto xj = p[0];
            auto yj = p[1];
            
            while(q.size()) {
                auto xi = q.front().first;
                if(xi >= xj - k)
                    break;
                q.pop_front();
            }
            
            if(q.size()) {
                auto xi = q.front().first;
                auto yi = q.front().second;
                res = max(res, yi - xi + xj + yj);
            }
            
            while(q.size()) {
                auto xi = q.back().first;
                auto yi = q.back().second;
                
                if(yi - xi > yj - xj)
                    break;
                
                q.pop_back();
            }
            
            q.push_back({xj, yj});
        }
        
        return res;
    }
};
 ```