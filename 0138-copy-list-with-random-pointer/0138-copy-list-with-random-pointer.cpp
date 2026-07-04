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
        Node* temp = head;
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            Node* front = temp->next;
            temp->next = newNode;
            newNode->next = front;
            temp = temp->next->next;
        }
        return head;
    }

    Node* addingptr(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* ran = temp->random;
            if(ran != NULL) temp->next->random = ran->next;
            else temp->next->random = ran;
            temp = temp->next->next;
        }
        return head;

    }
    Node* copyRandomList(Node* head) {
        Node* newNode = execute(head);
        Node* newN = addingptr(head);

        Node* temp = newN;
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;


        while(temp != NULL){
            Node* temp2 = temp->next;
            curr->next = temp2;
            curr = curr->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};