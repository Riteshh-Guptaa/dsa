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
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        int cnt = count(head);

        k %= cnt;
        if(k == 0) return head;

        int req = cnt - k;
        ListNode* temp = head;
        int i = 1;
        while(temp != NULL && i < req){
            temp = temp->next;
            i++;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* dummy = newHead;
        while(dummy->next){
            dummy = dummy->next;
        }
        dummy->next = head;
        head = newHead;
        return head;


    }
};