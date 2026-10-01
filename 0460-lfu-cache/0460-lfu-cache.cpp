class LFUCache {
struct Node{
    int value;
    int cnt;
    int key;
    Node* next;
    Node* prev;

    Node(int _value, int _key){
        value = _value;
        key = _key;
        next = NULL;
        cnt = 1;
        prev = NULL;
    }
};

struct List{
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int size;

    List(){
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        temp->prev = node;
        head->next = node;
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
int minFreq;
int cap;
int Cursize;

void updateFreqListMap(Node* node){
    mp.erase(node->key);
    List* newList = freqListMap[node->cnt];
    newList->removeNode(node);
    if(node->cnt == minFreq && newList->size == 0){
        minFreq++;
    }
    node->cnt +=1;
    List* list = freqListMap.find(node->cnt) != freqListMap.end() ? freqListMap[node->cnt] : new List();
    list->addFront(node);
    freqListMap[node->cnt] = list;
    mp[node->key] = node;
}

public:
    LFUCache(int capacity) {
        cap = capacity;
        Cursize = 0;
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

        if(Cursize == cap){
            List* list = freqListMap[minFreq];
            Node* node = list->tail->prev;
            list->removeNode(node);
            Cursize--;
            mp.erase(node->key);
            delete node;
        }

        Node* node = new Node(value, key);
        Cursize++;
        minFreq = 1;
        mp[key] = node;
        List* newList = freqListMap.find(1) == freqListMap.end() ? new List() : freqListMap[1];
        newList->addFront(node);
        freqListMap[1] = newList;
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */