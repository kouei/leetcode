# 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows

## Idea

`int bs(int sum, int r)` will answer this question:
from row `r` to the end of this matrix, what is the number of array whose sum is no greater than `sum`.


## Complexity

Time:  
O(RClog(R)log(C))

Space:  
O(R) (for recursion)

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
    vector<vector<int>> mat;
    int k;
    
    int kthSmallest(vector<vector<int>>& _mat, int _k) {
        swap(mat, _mat);
        swap(k, _k);
        
        int R = static_cast<int>(mat.size());
        int C = static_cast<int>(mat[0].size());
        
        
        int start = 1;
        int end = R * C * 5000;
        int res = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            int s = bs(mid, 0);
            
            if(s >= k) {
                res = mid;
                end = mid - 1;
            }
            
            else 
                start = mid + 1;
        }
        
        return res;
        
    }
    
    int bs(int sum, int r) {
        int R = static_cast<int>(mat.size());
        int C = static_cast<int>(mat[0].size());
        
        if(sum < 0)
            return 0;
        
        if(r == R) 
            return 1;
        
        int res = 0;
        
        for(int c = 0; c < C; ++c) {
            
            int t = bs(sum - mat[r][c], r + 1);
            
            if(t == 0)
                break;
            
            res += t;
            
            if(res > k)
                break;
        }
        
        return res;
    }
};
```