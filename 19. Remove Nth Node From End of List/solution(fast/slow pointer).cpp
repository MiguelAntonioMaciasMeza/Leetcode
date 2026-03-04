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
        
        ListNode dummyHead = ListNode(0, head);
        ListNode* fastPointer = &dummyHead;
        ListNode* slowPointer = &dummyHead;

        //Send fast node n positions ahead of slow pointer
        for(size_t i = 0; i < n; i++){
            fastPointer = fastPointer->next;
        }

        //till our fast pointer is not at the end
        //We increment both pointers
        while(fastPointer->next != NULL){
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }

        //Once at the end, update next pointer to remove it from list
        slowPointer->next = slowPointer->next->next;

        //Return dummyHead->next as that is the original/updated
        //head
        return dummyHead.next;

    }
};