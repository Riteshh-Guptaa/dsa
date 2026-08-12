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
        ListNode* frontNode = head->next;
        frontNode->next = head;
        head->next = NULL;
        return reverseHead;
    }

    ListNode* kthNode(ListNode* head, int k){
        int cnt = 1;
        while(head != NULL && cnt < k){
            head = head->next;
            cnt++;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* kth = kthNode(curr, k);
            if(kth == NULL){
                if(prev) prev->next = curr;
                return head;
            }

            ListNode* newNode = kth->next;
            kth->next = NULL;
            ListNode* reverseHead = reverse(curr);
            if(curr == head){
                prev = curr;
                head = reverseHead;
            }else{
                prev->next = reverseHead;
                prev = curr;
            }
            curr = newNode;
        }
        return head;
    }
};