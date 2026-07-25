/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        if(!root->left && !root->right){
            root->next = NULL;
            return root;
        }
       
       Node* current;
       std::queue<Node*> queue;
       queue.push(root);
       
       while(!queue.empty()){
        int level = queue.size();
        
        for(int i = 0; i < level; i++){
            current = queue.front();
            queue.pop();

            if(i != level -1){
                current->next = queue.front();
            }


            if(current->left)
                queue.push(current->left);
            
            if(current->right)
                queue.push(current->right);

        }
    }


        return root;
    }
};