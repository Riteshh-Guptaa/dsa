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

    ListNode* pivot(ListNode* head, int req){
        ListNode* curr = head;
        int cnt = 1;
        while(curr != NULL && cnt < req){
            cnt++;
            curr = curr->next;
        }
        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        
        int cnt = count(head);
        k %= cnt;
        if(k == 0) return head;
        int req = cnt - k;
        ListNode* newNode = pivot(head, req);
        ListNode* newHead = newNode->next;
        newNode->next = NULL;
        ListNode* temp = newHead;
        while(temp->next){
            temp = temp->next;
        }

        temp->next = head;
        return newHead;
        
    }
};