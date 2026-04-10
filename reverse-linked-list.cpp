//IAI
/* Given the head of a singly linked list, reverse the list, and return the reversed list.*/
/* Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]*/

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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        p1->next=nullptr;
        while(p2!=nullptr){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if (p3!=nullptr) p3 = p3->next;
        }
        return p1;
       
    }
};