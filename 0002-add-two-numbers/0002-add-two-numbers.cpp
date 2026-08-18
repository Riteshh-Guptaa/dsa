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
        ListNode* l = l1;
        ListNode* r = l2;
        int carry = 0;
        ListNode* dummy =new ListNode(-1);
        ListNode* curr = dummy;
        while(l !=  NULL || r != NULL){
            int sum = carry;
            if(l) {
                sum += l->val;
                l = l->next;
            }
            if(r) {
                sum += r->val;
                r = r->next;
            }
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
        }
        if(carry != 0){
            ListNode* newHead = new ListNode(carry);
            curr->next = newHead;
        
        }
        return dummy->next;
    }
};