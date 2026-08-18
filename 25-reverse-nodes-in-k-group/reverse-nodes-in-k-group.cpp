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

        ListNode* reverseHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return reverseHead;
    }

    ListNode* kthFinder(ListNode* head, int k){
        int cnt = 1;
        while(head != NULL && cnt < k){
            cnt++;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* kth = kthFinder(curr, k);
            if(kth == NULL){
                if(prev) prev->next = curr;
                return head;
            }
            ListNode* newNode = kth->next;
            kth->next = NULL;
            ListNode* reverseHead = reverse(curr);

            if(curr == head){
                head = reverseHead;
                prev = curr;
            }else{
                prev->next = reverseHead;
                prev = curr;
            }
            curr = newNode;
        }
        return head;
    }
};