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
    int counter(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = counter(head);
        if(k == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int ele = k - n;
        if(k < n){
            return head;
        }
        ListNode* temp = head;
        int cnt = 1;

        while(temp != NULL){
            if(ele == cnt){
                ListNode* res = temp->next;
                temp->next = res->next;
                return head;
            }
            cnt++;
            temp = temp->next;
        }
        return head;
    }
};