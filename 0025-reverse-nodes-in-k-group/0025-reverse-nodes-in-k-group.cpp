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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* frontNode = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return frontNode;
    }
    ListNode* kthElement(ListNode* head, int k){
        ListNode* curr = head;
        int cnt = 1;
        while(curr != NULL && cnt < k){
            curr = curr->next;
            cnt++;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* kth = kthElement(curr, k);
            if(kth == NULL){
                if(prev) prev->next = curr;
                return head;
            }

            ListNode* temp = kth->next;
            kth->next = NULL;
            ListNode* reverseHead = reverse(curr);

            if(curr == head){
                head = reverseHead;
                prev = curr;
            }else{
                prev->next = reverseHead;
                prev = curr;
            }
            curr = temp;
        }
        return head;

    }
};