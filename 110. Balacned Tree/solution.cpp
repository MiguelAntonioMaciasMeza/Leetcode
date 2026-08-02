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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        return checkHeight(root) != -1;
    }

    int checkHeight(TreeNode* node){
        if(!node)   return 0;

        int left = checkHeight(node->left);
        if(left == -1) return -1;

        int right = checkHeight(node->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1; // if we already have a height discrepancy of more than 1 anywhere, we abandon early

        return 1 + max(left, right); // 1 + max height of either one of its subtrees 


    }
};