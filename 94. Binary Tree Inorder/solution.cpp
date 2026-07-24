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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        std::vector<int> result;
        TreeNode* current = root;
        std::stack<TreeNode*> stack;

        //While we have an existign node and something in stack
        while(current || !stack.empty()){

            //Node exist keep pushing itself and check for left
           while(current){
            stack.push(current);
            current = current->left;
           }

           //Node does not exist, check stack, get val, and pop
           current = stack.top();
           result.push_back(current->val);
           stack.pop();

           //Add right node to stack, if it exist, will keep pushing left nodes to stack, if not, will go to last known
           //node from stack. 
           current = current->right;

        }

        return result;
        
    }
};