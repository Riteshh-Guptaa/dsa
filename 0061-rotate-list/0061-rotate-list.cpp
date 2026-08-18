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
    int count(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        ListNode * temp = head;
        int cnt = count(head);
        k %= cnt;
        if(k == 0) return head;
        int req = cnt - k;
        int i = 1;
        while(temp != NULL && i < req){
            temp = temp->next;
            i++;
        }
        ListNode* newNode = temp->next;
        temp->next = NULL;
        ListNode* curr = newNode;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = head;
        return newNode;

    }
};