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
    ListNode* kth(ListNode* head, int k){
        int len = 1;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL && len != k ) {
            len++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt = 1;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            cnt++;
            temp = temp->next;
        }

        if(k % cnt == 0)return head;
        k %= cnt;

        ListNode* newNode = kth(head, cnt - k);
        ListNode* newHead = newNode->next;
        temp->next = head;
        newNode->next = NULL;
        return newHead;
    }
};