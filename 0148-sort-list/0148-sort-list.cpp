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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* node1, ListNode* node2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(node1 != NULL && node2 != NULL){
            if(node1->val > node2->val){
                temp->next = node2;
                temp = temp->next;
                node2 = node2->next;
            }else{
                temp->next = node1;
                temp = temp->next;
                node1 = node1->next;
            }
            temp->next = nullptr;
        }

        while(node1) {
            temp->next = node1;
            temp = temp->next;
            node1 = node1->next;
            temp->next = nullptr;
        } 
        while(node2) {
            temp->next = node2;
            temp = temp->next;
            node2 = node2->next;
            temp->next = nullptr;
        }
        return dummy->next;
    }
    ListNode* mergeSort(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* low = head;
        ListNode* middle = findMiddle(head);
        ListNode* high = middle->next;
        middle->next = nullptr;

        low = mergeSort(low);
        high = mergeSort(high);
       return merge(low, high);

    }
    ListNode* sortList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        return mergeSort(head);
    }
};