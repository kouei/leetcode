# 1483. Kth Ancestor of a Tree Node

## Idea

The idea is borrowed from a data structure called **Skip List**.

ancestor[i][j] means the **2^j** th ancestor of node **i**.

## Complexity

H = height of the original tree
Q = number of queries

Time:  
O(Q * log(k))

Space:  
O(n * log(H))

## C++
```C++
static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


int ancestor[17][50010];
int height[50010];
int level;

class TreeAncestor {
public:
    
    int get_height(int i, vector<int>& parent) {
        return height[i] != -1 ? height[i] : (height[i] = parent[i] == -1 ? 1 : get_height(parent[i], parent) + 1);
    }
    
    
    TreeAncestor(int n, vector<int>& parent) {
        memset(height, 0xff, sizeof(height[0]) * n);
        
        int h = 0;
        for(int i = 0; i < n; ++i)
            h = max(h, get_height(i, parent));
        
        level = 0;
        while((1 << level) < h)
            level += 1;
        level += 1;

        memcpy(&ancestor[0][0], &parent[0], sizeof(parent[0]) * n);
        for(int i = 1; i < level; ++i) {
            for(int j = 0; j < n; ++j) {
                ancestor[i][j] = ancestor[i - 1][j] == -1 ? -1 : ancestor[i - 1][ancestor[i - 1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur = node;
        int cur_level = k;
        for(int i = level - 1; i >= 0; --i) {
            while(cur_level >= (1 << i)) {
                cur_level -= (1 << i);
                cur = ancestor[i][cur];
                if(cur == -1)
                    return cur;
            }
        }
        
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
 ```