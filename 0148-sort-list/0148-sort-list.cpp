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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* temp1 = left;
        ListNode* temp2 = right;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;


        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val >= temp2->val){
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }else{
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }
            temp->next = NULL;
        }

        while(temp1) temp->next = temp1, temp1 = temp1->next, temp = temp->next;
        while(temp2) temp->next = temp2, temp2 = temp2->next, temp = temp->next;

        return dummyNode->next;
    }
    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;
        while( fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = slow->next;
        slow->next = NULL;
        ListNode* left = head;

        ListNode* low = mergeSort(left);
        ListNode* high = mergeSort(right);
        return merge(low, high);
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
      

        return mergeSort(head);
    }
};