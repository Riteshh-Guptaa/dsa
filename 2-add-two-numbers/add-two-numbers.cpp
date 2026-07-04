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
       ListNode* left = l1;
       ListNode* right = l2;

       ListNode* newN = new ListNode(-1);
       ListNode* curr = newN;
       int carry = 0;

       while(left != NULL || right != NULL){
           int sum = carry;
           if(left){
            sum += left->val;
            left = left->next;
           }
           if(right){
            sum += right->val;
            right = right->next;
           }
           carry = sum/10;
           curr->next = new ListNode(sum % 10);
           curr = curr->next;
       }
       if(carry){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
       }
       return newN->next;
    }
};