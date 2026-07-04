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

        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* kthFinder(ListNode* head, int k){
        int cnt = 1;
        while(head != NULL && cnt < k){
            head = head->next;
            cnt++;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* kth = kthFinder(temp, k);
            if(kth == NULL){
                if(prev) prev->next = temp;
                return head;
            }
            ListNode* newNode = kth->next;
            kth->next = NULL;
            ListNode* reverseHead = reverse(temp);

            if(temp == head){
                prev = temp;
                head = reverseHead;
            }else{
                prev->next = reverseHead;
                prev = temp;
            }
            temp = newNode;
        }
        return head;
    }
};