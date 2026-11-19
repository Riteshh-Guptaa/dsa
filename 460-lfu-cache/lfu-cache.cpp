class LFUCache {
struct Node{
    int val;
    int key;
    int cnt;
    Node* next;
    Node* prev;

    Node(int _val, int _key){
        val = _val;
        key = _key;
        cnt = 1;
    }
};

struct List{
    Node* head;
    Node* tail;
    int size;

    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void removeNode(Node* node){
        Node* frontNode = node->next;
        Node* backNode = node->prev;

        frontNode->prev = backNode;
        backNode->next = frontNode;
        size--;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        temp->prev = node;
        head->next = node;
        node->next = temp;
        node->prev = head;
        size++;
    }
};

unordered_map<int, Node*> mp;
unordered_map<int, List*> freqListMap;
int curSize;
int cap;
int minFreq;


void updateFreqListMap(Node* node){
    List* list = freqListMap[node->cnt];
    list->removeNode(node);
    if(list->size == 0 && minFreq == node->cnt){
        minFreq++;
    }

    node->cnt++;

    List* newList = freqListMap.find(node->cnt) == freqListMap.end() ? new List() : freqListMap[node->cnt];
    newList->addFront(node);
    freqListMap[node->cnt] = newList;
};

public:
    LFUCache(int capacity) {
        cap = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];
        int x = node->val;
        updateFreqListMap(node);
        return x;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            updateFreqListMap(node);
            return;
        }
        if(curSize == cap){
            List* delList = freqListMap[minFreq];
            Node* temp = delList->tail->prev;
            delList->removeNode(temp);
            mp.erase(temp->key);
            curSize--;
            delete temp;
        }

        Node* node = new Node(value, key);
        minFreq = 1;
        List* list = freqListMap.find(minFreq) == freqListMap.end() ? new List() : freqListMap[minFreq];
        list->addFront(node);
        mp[key] = node;
        freqListMap[minFreq] = list;
        curSize++;

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */