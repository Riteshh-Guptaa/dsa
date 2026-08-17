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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* reverseHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return reverseHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == NULL || head->next == NULL){
            return true;
        }

        fast = fast->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newNode = slow->next;
        slow->next = NULL;
        ListNode* temp = head;
        ListNode* reverseHead = reverse(newNode);
        while(reverseHead){
            if(reverseHead->val != temp->val){
                return false;
            }
            reverseHead = reverseHead->next;
            temp = temp->next;
        }
        return true;
    }
};