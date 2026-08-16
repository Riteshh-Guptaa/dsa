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
        int cnt = count(head);
        int req = cnt - n;
        if(req == 0){
            if(head) return head->next;
            else NULL;
        }
        ListNode* temp = head;
        int i = 1;
        while(temp != NULL && i < req){
            temp = temp->next;
            i++;
        }
        ListNode* newNode = NULL;
        ListNode* deletedone = temp->next;
        if(deletedone) newNode = deletedone->next;
        temp->next = newNode;
        delete deletedone;
        return head;
    }
};