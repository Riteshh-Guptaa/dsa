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
   int size;
   Node* head;
   Node* tail;
   List(){
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
    size = 0;
   }
   void addFront(Node* node){
    Node* temp = head->next;
    node->next = temp;
    node->prev = head;
    head->next = node;
    temp->prev = node;
    size++;
   }

   void removeNode(Node* node){
    Node* nodePrev = node->prev;
    Node* nodeFront = node->next;
    nodePrev->next = nodeFront;
    nodeFront->prev = nodePrev;
    size--;
   }
};

int maxSizeCache;
int curSize;
int minFreq;

unordered_map<int, Node*> mp;
unordered_map<int, List*> freqListMap;

void updateFreqListMap(Node* node){
    
    List* newList = freqListMap[node->cnt];
    newList->removeNode(node);
    if(newList->size == 0 && minFreq == node->cnt){
        minFreq++;
    }
    node->cnt += 1;

    List* list = (freqListMap.find(node->cnt) == freqListMap.end()) ? new List() : freqListMap[node->cnt];
    list->addFront(node);
    freqListMap[node->cnt] = list;
}
public:


    LFUCache(int capacity) {
        maxSizeCache = capacity;
        curSize = 0;
        minFreq = 1;
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
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            updateFreqListMap(node);
            return;
        }

        if(curSize == maxSizeCache){
            List* list = freqListMap[minFreq];
            Node* node = list->tail->prev;
            mp.erase(node->key);
            list->removeNode(node);
            delete node;
            curSize--;
        }

        minFreq = 1;
        curSize++;
        Node* node = new Node(value, key);
        List* newList = (freqListMap.find(1) == freqListMap.end()) ? new List() : freqListMap[1];
        newList->addFront(node);
        freqListMap[1] = newList;
        mp[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */