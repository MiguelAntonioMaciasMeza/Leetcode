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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> paths;
        std::vector<int> currentPath;
        if(!root)
            return {};

        backTrack(root, targetSum, paths, currentPath);
    return paths;
    }

    void backTrack(TreeNode* node, int targetSum, std::vector<vector<int>>& paths, std::vector<int>& currentPath){
        if(!node)
            return;

        
        targetSum -= node->val;
        if(!node->left && !node->right){
            if(targetSum == 0){
                currentPath.push_back(node->val);
                paths.push_back(currentPath);
                currentPath.pop_back();
                return;
            }
        }

        currentPath.push_back(node->val);
        if(node->left)
            backTrack(node->left,targetSum, paths, currentPath);
        if(node->right)
            backTrack(node->right, targetSum, paths, currentPath);
        currentPath.pop_back();
    }
};