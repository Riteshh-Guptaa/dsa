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
    int cnt(ListNode* head){
        ListNode* curr = head;
        int count = 0;
        while(curr){
            curr = curr->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        int count = cnt(head);
        k %= count;
        if(k == 0) return head;

        int i = 1;
        ListNode* temp = head;
        while(temp != NULL && i < count - k){
            temp = temp->next;
            i++;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* curr = newHead;
        while(curr->next){
            curr = curr->next;
        }

        curr->next = head;
        return newHead;
    }
};