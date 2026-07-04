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
    ListNode* counter(ListNode* head, int kc){
        ListNode* temp = head;
        int cnt = 1;
        while(temp != NULL && cnt != kc){
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
  
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 1;
        while(temp != NULL && temp->next != NULL){
            len++;
            temp = temp->next;
        }
        if(k >= len){
            k %= len;
        }
        if(k == 0){
            return head;
        }

        temp->next = head;
        ListNode* newNode = counter(head, len - k);
        head = newNode->next;
        newNode->next = NULL;
        return head;
    }
};