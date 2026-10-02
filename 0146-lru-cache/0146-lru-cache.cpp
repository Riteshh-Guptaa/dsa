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

unordered_map<int, Node*> mp;
Node* head;
Node* tail;
int cap;

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
        head->next = node;
        temp->prev = node;
        node->prev = head;
        node->next = temp;
    }

    void removeNode(Node* node){
        Node* nodeFront = node->next;
        Node* nodeBack = node->prev;
        nodeFront->prev = nodeBack;
        nodeBack->next = nodeFront;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];
        int val = node->value;
        removeNode(node);
        addFront(node);
        return val;
    } 
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            removeNode(node);
            node->value = value;
            addFront(node);
            return;

        }

        if(mp.size() == cap){
            Node* node = tail->prev;
            mp.erase(node->key);
            removeNode(node);
            delete node;
        }

        Node* node = new Node(value, key);
        mp[key] = node;
        addFront(node);

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */