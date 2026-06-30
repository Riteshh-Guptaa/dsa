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
    ListNode* rotated(ListNode* head, int k){
        int cnt = 1;
         ListNode* temp = head;
     while(temp->next != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;

       
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }
        if(k % len == 0) return head;
        k %= len;

        tail->next = head;
        ListNode* ele = rotated(head, len - k);
        head = ele->next;
        ele->next = NULL;
        return head;  
    }
};