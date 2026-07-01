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
    Node* addNode(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* newN = new Node(temp->val);
            newN->next = temp->next;
            temp->next = newN;
            temp = newN->next;
        }
        return head;
    }

    Node* addRandom(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* ran = temp->random;
            if(ran != NULL){
                temp->next->random = ran->next;
            }else{
                temp->next->random = nullptr;
            }

            temp = temp->next->next;
        }
        return head;
    }

    Node* extract(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* curr = dummy;

        while(temp != NULL){
            curr->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            curr = curr->next;
        }

        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        Node* temp = addNode(head);
        Node* r = addRandom(temp);
        return extract(r);

    }
};