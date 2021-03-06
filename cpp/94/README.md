# 94. Binary Tree Inorder Traversal

## Idea

Morris Traversal Algorithm

## Complexity

Time:  
O(N)
  
Space:  
O(1)

## C++
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> res;
        TreeNode * cur = root;
        while(cur) {
            if(!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
                continue;
            }
            
            TreeNode * prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;
            
            if(!prev->right) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
 ```