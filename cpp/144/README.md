# 144. Binary Tree Preorder Traversal

## Idea

Morris Traversal Algorithm

## Complexity
Time: O(N)  
Space: O(1)

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

static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        auto cur = root;
        while(cur) {
            
            if(!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
                continue;
            }
            
            auto prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;
            
            if(!prev->right) {
                res.push_back(cur->val);
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
        return res;
    }
};
```