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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        
        ListNode* tail = head;
        int length = 1;
        while(tail->next != NULL){
            tail = tail->next;
            length++;
        }
        

        int effectiveK = k % length;
        //If zero effective rotations just return head
        if(effectiveK == 0){
            return head;
        }
        //Make the linked list circular
        tail->next = head;
        ListNode* newTail = head;
       
        //Get new tail by rotating length - effectiveRotation -1; 
        //Without -1 we'd be at the new head, so now we know that newTail->next would be 
        //new head
        for(int i = 0; i < length - effectiveK - 1; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL; //cut off linked list


        return newHead;
    }
};
