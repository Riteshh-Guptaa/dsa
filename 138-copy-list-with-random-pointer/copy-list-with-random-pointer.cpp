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
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        return head;
    }

    Node* addingptrs(Node* head){
        Node* temp = head;
        while(temp){
            Node* randomPtrs = temp->random;
            if(randomPtrs) temp->next->random = randomPtrs->next;
            else temp->next->random = NULL;
            temp = temp->next->next;
        }
        return head;
    }
    Node* copyRandomList(Node* head) {
        Node* newN = execute(head);
        Node* temp = addingptrs(newN);

        Node* dummy = new Node(-1);
        Node* curr = dummy;
        while(temp){
            curr->next = temp->next;
            temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};