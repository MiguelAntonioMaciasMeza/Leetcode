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
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        
        int currentTotal = 0;
        int total = dfs(root,currentTotal);
        
        return total;

    }

    int dfs(TreeNode* node, int currentTotal){
        if(!node)
            return 0;
        //Add to new current total
        currentTotal = currentTotal * 10 + node->val;

        //If child node, just return the total
        if(!node->left && !node->right){
            return currentTotal;
        }

        //Add both left and right tree
        return dfs(node->left,currentTotal) + dfs(node->right, currentTotal);
    }

};