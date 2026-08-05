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
        
        ListNode* next = head;
        int length = 1;
        while(next->next != NULL){
            next = next->next;
            length++;
        }
        next = head->next;

        ListNode* previous = head;
        for(int i = 0; i < k % length; i++){

            while(next->next != NULL){
                next = next->next;
                previous = previous->next;
            }
            ListNode* temp = head; // Has 1-5
            previous->next = NULL; //Becomes new tail
            head = next;
            head->next = temp;
            next = head->next;
            previous = head;
        }
        return head;
    }
};
