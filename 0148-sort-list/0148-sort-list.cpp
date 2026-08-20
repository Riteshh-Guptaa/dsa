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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* left = l1;
        ListNode* right = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(left != NULL && right != NULL){
            if(left->val > right->val){
                curr->next = right;
                right = right->next;
                curr = curr->next;
            }else{
                curr->next = left;
                curr = curr->next;
                left = left->next;
            }
        }

        while(left) curr->next = left, curr = curr->next, left = left->next;
        while(right) curr->next = right, curr = curr->next, right = right->next;

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* rightHalf = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);
        ListNode* merg = merge(left, right);
        return merg;
    }
};