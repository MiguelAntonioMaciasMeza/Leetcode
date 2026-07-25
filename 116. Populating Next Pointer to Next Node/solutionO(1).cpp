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
       
        Node* head = root;
        //While we haven't reached beyond far left
        while(root){
            Node* current = root;// Start at the same root
            //As long as it's valid
            while(current){

            //Check if it has a left child
            if(current->left){
                //If so assign that left's child to this current right
                current->left->next = current->right;
                //If our current node points to a node to its right, we get the right's left node
                //and point it to this node's right next
                if(current->next){
                    current->right->next = current->next->left;
                }
            }else{
                break;
            }
            //Move horizontally, if not valid we move our root node down one to the left
            current = current->next;
        }
        root = root->left;
        }
        
        return head;
    }
};