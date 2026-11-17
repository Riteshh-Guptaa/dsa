class LFUCache {
struct Node{
    int val;
    Node* next;
    int cnt;
    Node* prev;
    int key;

    Node(int _val, int _key){
        val = _val;
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
        temp->prev = node;
        head->next = node;
        node->next = temp;
        node->prev = head;
        size++;
    }

    void removeNode(Node* node){
        Node* frontNode = node->next;
        Node* prevNode = node->prev;
        frontNode->prev = prevNode;
        prevNode->next = frontNode;
       
        size--;
    }
};

unordered_map<int, Node*> mp;
unordered_map<int, List*> freqListMap;
int cap;
int curSize;
int minFreq;

void updateFreqListMap(Node* node){
    List* list = freqListMap[node->cnt];
    list->removeNode(node);
    if(list->size == 0 && minFreq == node->cnt){
        minFreq++;
    }

    node->cnt += 1;

    List* newList = freqListMap.find(node->cnt) != freqListMap.end() ? freqListMap[node->cnt] : new List();
    newList->addFront(node);
    freqListMap[node->cnt] = newList;
}
public:
    LFUCache(int capacity) {
        cap = capacity;
        curSize = 0;
        minFreq = 0;       
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

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
            List* newList = freqListMap[minFreq];
            Node* delNode = newList->tail->prev;
            newList->removeNode(delNode);
            mp.erase(delNode->key);
            delete delNode;
            curSize--;
        }

        Node* newNode = new Node(value, key);
        minFreq = 1;
        List* list = freqListMap.find(minFreq) == freqListMap.end() ? new List() : freqListMap[minFreq];
        list->addFront(newNode);
        freqListMap[minFreq] = list;
        mp[key] = newNode;
        curSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */