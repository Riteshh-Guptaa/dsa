class LRUCache {
struct Node{
    int value;
    int key;
    Node* next;
    Node* prev;

    Node(int _value, int _key){
        value = _value;
        key = _key;
        next = nullptr;
        prev = nullptr;
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
        Node* newNode = head->next;
        node->next = newNode;
        node->prev = head;
        newNode->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node){
        Node* delPrev = node->prev;
        Node* delFront = node->next;

        delPrev->next = delFront;
        delFront->prev = delPrev;
        
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
        addFront(node);
        mp[key] = node;

        if(mp.size() > cap){
            Node* delNode = tail->prev;
            mp.erase(delNode->key);
            removeNode(delNode);
            delete delNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */