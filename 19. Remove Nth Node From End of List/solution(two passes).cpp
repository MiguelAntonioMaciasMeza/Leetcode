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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* previous = head;
        ListNode* next = head->next;
        int depth = 0;

        //Handle edge case where head is the only element 
        if(head->next == NULL)
            return NULL;
        
        while(next != NULL){
            next = next->next;
            depth++;
        }

        //Edge case where we cant get deep enough yo what
        if(depth < n){
            head = head->next;
        }

        while(depth > n){
            previous = previous->next;
            depth--;
        }

        //Swap
        previous->next = previous->next != NULL? previous->next->next: NULL;

        return head;
    }
};