class LFUCache {
struct Node{
    int key, cnt, value;

    Node* next;
    Node* prev;

    Node(int _value, int _key){
        value = _value;
        key = _key;
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

    void addFront(Node* node){
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

unordered_map<int, Node*> nodekey;
unordered_map<int, List*> listMap;

void updateListMap(Node* node){
   nodekey.erase(node->key);
   List *list = listMap[node->cnt];
   list->removeNode(node);

   if(minFreq == node->cnt && list->size == 0){
    minFreq += 1;
   }

   node->cnt += 1;

   List *newList = listMap.find(node->cnt) == listMap.end() ? new List() : listMap[node->cnt];

   newList->addFront(node);
   listMap[node->cnt] = newList;
   nodekey[node->key] = node;

}

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    int get(int key) {
        if(nodekey.find(key) == nodekey.end()){
            return -1;

        }

        Node* node = nodekey[key];
        int value = node->value;
        updateListMap(node);
        return value;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }

        if(nodekey.find(key) != nodekey.end()){
            Node *node = nodekey[key];
            node->value = value;
            updateListMap(node);
            return;
        }

        if(curSize == maxSizeCache){
            List* list = listMap[minFreq];
            Node* node = list->tail->prev;
            int key = node->key;
            nodekey.erase(key);
            list->removeNode(node);
            delete node;
            curSize--;
        }

        curSize++;
        Node* node = new Node(value, key);
        minFreq = 1;
        List* list = listMap.find(node->cnt) == listMap.end() ? new List() : listMap[node->cnt];
        list->addFront(node);
        nodekey[node->key] = node;
        listMap[node->cnt] = list;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */