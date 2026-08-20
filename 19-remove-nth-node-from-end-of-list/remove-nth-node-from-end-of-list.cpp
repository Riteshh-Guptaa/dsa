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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        int cnt = count(head);
        int req = cnt - n;

        if(req == 0){
            head = head->next;
            return head;
        }
        ListNode* temp = head;
        int i = 1;
        while(temp != NULL && i < req){
            i++;
            temp= temp->next;
        }

        ListNode* duplicate = temp->next;
        temp->next = temp->next->next;
        delete duplicate;
        return head;
    }
};