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
        if(head == NULL || head->next == NULL){
            return head;
        }    
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* newHead = slow->next;
        slow->next = NULL;

        ListNode* reverseHead = reverse(newHead);

        while(reverseHead != NULL){
            if(reverseHead->val != head->val){
                return false;
            }

            reverseHead = reverseHead->next;
            head = head->next;
        }
        return true;
    }
};