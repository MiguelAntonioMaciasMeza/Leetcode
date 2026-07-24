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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        if(!root->left && !root->right)
            return;
        std::queue<TreeNode*> queue;
        preOrder(queue,root);
           
          
        int size = queue.size();
        for(int i = 0; i < size -1 ; i++){
            TreeNode* current = queue.front();
            queue.pop();
            TreeNode* next = queue.front();
            current->left = NULL;
            current->right = next;
        }
    }

    void preOrder(std::queue<TreeNode*>& queue, TreeNode* node){
        if(!node)
            return;

        if(node)
            queue.push(node);
        preOrder(queue,node->left);
        preOrder(queue,node->right);
    }
};