class LRUCache {
struct Node{
    int value;
    int key;
    Node* next;
    Node* prev;
    
    Node(int _value, int _key){
        value = _value;
        key = _key;
        next = NULL;
        prev = NULL;
    }
};

int cap;

unordered_map<int, Node*> mp;

Node* head;
Node* tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void removeNode(Node* node){
        Node* delFront = node->next;
        Node* delPrev = node->prev;
        delFront->prev = delPrev;
        delPrev->next = delFront;

    }
    
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];
        int value = node->value;
        removeNode(node);
        addFront(node);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            addFront(node);
            return;
        }

        Node* node = new Node(value, key);
        mp[key] = node;
        addFront(node);

        if(mp.size() > cap){
            Node* delnode = tail->prev;
            mp.erase(delnode->key);
            removeNode(delnode);
            delete delnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */