class LFUCache {
struct Node{
    int value;
    int key;
    int cnt;
    Node* next;
    Node* prev;

    Node(int _value, int _key){
        value = _value;
        key = _key;
        next = NULL;
        prev = NULL;
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

    void addFront(Node* node){
        Node* temp = head->next;
        head->next = node;
        temp->prev = node;
        node->next = temp;
        node->prev = head;
        size++;
    }

    void removeNode(Node* node){
        Node* nodeFront = node->next;
        Node* nodeBack = node->prev;
        nodeFront->prev = nodeBack;
        nodeBack->next = nodeFront;
        size--;
    }


};

unordered_map<int, Node*> mp;
unordered_map<int, List*> freqListMap;
int cap;
int minFreq;
int curSize;

void updateFreqListMap(Node* node){
    List* newList = freqListMap[node->cnt];
    newList->removeNode(node);
    if(minFreq == node->cnt && newList->size == 0){
        minFreq++;
    }

    node->cnt += 1;

    List *list = freqListMap.find(node->cnt) == freqListMap.end() ? new List() : freqListMap[node->cnt];
    list->addFront(node);
    freqListMap[node->cnt] = list; 
}

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
        int val = node->value;
        updateFreqListMap(node);
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            updateFreqListMap(node);
            return;
        }

        if(cap == curSize){
            List* newList = freqListMap[minFreq];
            Node* node = newList->tail->prev;
            newList->removeNode(node);
            mp.erase(node->key);
            delete node;
            curSize--;
        }

        Node* node = new Node(value, key);
        mp[key] = node;
        minFreq = 1;
        List* list = freqListMap.find(node->cnt) == freqListMap.end() ? new List() : freqListMap[node->cnt];
        list->addFront(node);
        freqListMap[node->cnt] = list;
        curSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */