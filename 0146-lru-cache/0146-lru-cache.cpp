class LRUCache {
public:
    struct Node{
        int value;
        Node* next;
        Node* prev;

        Node(int val){
            value = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int cap;

    unordered_map<Node*, int> nodekey;
    unordered_map<int, Node*> mp;

    Node* head = new Node(-1);
    Node* tail = new Node(-1);


    LRUCache(int capacity) {
        cap = capacity;

        head->next = tail;
        tail->prev = head;

    }

    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void insertNode(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];
        removeNode(node);
        insertNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            insertNode(node);
            return;
        }

        if(mp.size() == cap){
            Node* lru = tail->prev;
            int newKey = nodekey[lru];
            nodekey.erase(lru);
            mp.erase(newKey);
            removeNode(lru);
            delete lru;
        }

        Node* node = new Node(value);
        mp[key] = node;
        nodekey[node] = key;
        insertNode(node); 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */