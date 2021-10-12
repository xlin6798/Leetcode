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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* curr = ret;
        int ones = 0, tens = 0;
        int x, y;
        while (l1 != nullptr || l2 != nullptr) {
            x = (l1!=nullptr) ? l1->val : 0;  //if null x=val ? x=0
            y = (l2!=nullptr) ? l2->val : 0;  //if null y=val ? y=0
            ones = (x+y+tens)%10;
            tens = (x+y+tens)/10;
            curr->next = new ListNode(ones);
            curr = curr->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if (tens == 1) curr->next = new ListNode(tens);
        return ret->next; //first node for initialization
    }
};