# 145. Binary Tree Postorder Traversal

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

static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> res;
        
        if (!root) 
            return res;
        
        TreeNode * dummy = new TreeNode;
        dummy->left = root;
        
        TreeNode * node = dummy;
        while (node) {
            if (!node->left)
                node = node->right;
            else {
                TreeNode * pre = getPrenode(node);
                if (!pre->right) {
                    pre->right = node;
                    node = node->left;
                } else {
                    printReverse(node->left, pre, res);
                    pre->right = nullptr;
                    node = node->right;
                }
            }
        }
        return res;
    }
    
    TreeNode* getPrenode(TreeNode* node) {
        TreeNode * pre = node->left;
        while (pre->right && pre->right != node) 
            pre = pre->right;
        return pre;
    }
    
    void printReverse(TreeNode* leftNode, TreeNode* pre, vector<int>& res) {
        reverse(leftNode, pre);
        TreeNode * node = pre;
        res.push_back(node->val);
        while (node != leftNode) {
            node = node->right;
            res.push_back(node->val);
        }
        reverse(pre, leftNode);
    }
    
    void reverse(TreeNode* node1, TreeNode* node2) {
        TreeNode * x = node1;
        TreeNode * y = x->right;
        while (x != node2) {
            TreeNode * temp = y->right;
            y->right = x;
            x = y;
            y = temp;
        }
    }
};
```