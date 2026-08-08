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
            curr = curr->next->next;
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

        Node* curr = head;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        
        while(curr){
            prev->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            prev = prev->next;
        }
        return dummy->next;
    }
};