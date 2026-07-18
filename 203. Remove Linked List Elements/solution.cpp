/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    
        if(head == NULL)
            return NULL;

        if(head->val == val){
            head = head->next;
            return removeElements(head, val);
        }else{
            
            //Check next node to see if we need to swap
            if(head->next != NULL){
                ListNode* next = head->next;
                if(next->val == val){
                    head->next = next->next;
                    removeElements(head,val);
                }
            
            }
            removeElements(head->next,val);
        }
        return head;
    }
};