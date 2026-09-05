class LFUCache {
struct Node{
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
 };

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node){
        Node* delprev = node->prev;
        Node* delfront = node->next;
        delprev->next = delfront;
        delfront->prev = delprev;
        size--;
    }
};

int maxSizeCache;
int minFreq;
int curSize;

unordered_map<int, Node *> keyNode;
unordered_map<int, List *> freqListMap;

void updateFreqListMap(Node* node){
    keyNode.erase(node->key);
    List *list = freqListMap[node->cnt];
    list->removeNode(node);

    if(node->cnt == minFreq && list->size == 0){
        minFreq++;
    }

    node->cnt += 1;

    List *newList = (freqListMap.find(node->cnt) != freqListMap.end()) ? freqListMap[node->cnt] : new List(); 
    newList->addFront(node);
    keyNode[node->key] = node;
    freqListMap[node->cnt] = newList;

}
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;    
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()){
            return -1;
        }

        Node *node = keyNode[key];
        int value = node->value;
        updateFreqListMap(node);
        return value;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }

        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
            return;
        }

        if(curSize == maxSizeCache){
            List *list = freqListMap[minFreq];
            Node* nodetodelete = list->tail->prev;
            keyNode.erase(nodetodelete->key);
            
            freqListMap[minFreq]->removeNode(nodetodelete);
            delete nodetodelete;
            curSize--;
        }


        curSize++;
        minFreq = 1;

        Node *node = new Node(key, value);
        List *listFreq = (freqListMap.find(1) != freqListMap.end()) ? freqListMap[1] : new List();

        listFreq->addFront(node);
        freqListMap[1] = listFreq;
        keyNode[key] = node; 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */