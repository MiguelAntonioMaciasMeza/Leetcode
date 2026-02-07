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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

       //Either Either list is empty just return them,no need to comapre
        if (list1 == nullptr){
            return list2;
        }else if (list2 == nullptr){
            return list1;
        }
        
        //If the value of list one is less than or = to list 2
        //We assign our head to it
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);  
            return list1;
        }else if (list2->val <= list1->val){
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

        return list1;
    }

};