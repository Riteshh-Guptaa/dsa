/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* execute(Node* head){
        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        return head;
    }

    Node* addingptr(Node* head){
        Node* curr = head;
        while(curr){
            Node* temp = curr->random;
            if(temp) curr->next->random = temp->next;
            else curr->next->random = temp;
            curr = curr->next->next;
        }
        return head;
    }
    Node* copyRandomList(Node* head) {
        Node* newN = execute(head);
        Node* newNode = addingptr(head);
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        Node* temp = head;
        while(temp){
            curr->next = temp->next;
            temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};