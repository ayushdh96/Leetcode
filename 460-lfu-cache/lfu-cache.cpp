class LFUCache {
public:
    class Node{
        public:
        Node* next;
        Node* prev;
        int key;
        int value;
        int count;
        Node(int key, int value){
            next=nullptr;
            prev=nullptr;
            this->key=key;
            this->value=value;
            count=1;
        }
    };
    int cap=0, minCount=1;
    int capacityCounter=0;
    map<int, Node*> keyAddMap;
    map<int, pair<Node*,Node*>> counterLinkedListMap;
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    void deleteNode(Node* keyNodeTemp, int counting){
        Node* traversal=keyNodeTemp;
        Node* deletNode1=keyNodeTemp->prev;
        Node* deletNode2=keyNodeTemp->next;
        deletNode1->next=deletNode2;
        deletNode2->prev=deletNode1;
        traversal->next=nullptr;
        traversal->prev=nullptr;
        if(deletNode1->prev==nullptr && deletNode2->next==nullptr){
            counterLinkedListMap.erase(counting);
        }
        capacityCounter--;
    }

    void addNode(Node* keyNodeTemp,int key){
        if(counterLinkedListMap.find(key)==counterLinkedListMap.end()){
            Node* dumdumHead=new Node(-1,-1);
            Node* dumdumtail=new Node(-1,-1);
            dumdumHead->next=keyNodeTemp;
            dumdumtail->prev=keyNodeTemp;
            keyNodeTemp->prev=dumdumHead;
            keyNodeTemp->next=dumdumtail;
            counterLinkedListMap[key]={dumdumHead,dumdumtail};
            
        }
        else{
            Node* dumdumHeadTemp=counterLinkedListMap[key].first;
            Node* storingHeadNextTemp=dumdumHeadTemp->next;
            dumdumHeadTemp->next=keyNodeTemp;
            keyNodeTemp->prev=dumdumHeadTemp;
            keyNodeTemp->next=storingHeadNextTemp;
            storingHeadNextTemp->prev=keyNodeTemp;
        }
        capacityCounter++;
    }

    int get(int key) {
        if(keyAddMap.find(key)==keyAddMap.end()){
            return -1;
        }
        else{
             Node* temp=keyAddMap[key];
             int counter=temp->count;
            deleteNode(temp,counter);
            counter++;
            temp->count=counter;
            addNode(temp,counter);
            return temp->value;
        }
    }
    
    void put(int key, int value) {
        if(keyAddMap.find(key)!=keyAddMap.end()){
            Node* temp=keyAddMap[key];
            temp->value=value;
            deleteNode(temp,temp->count);
            int counter=temp->count;
            counter++;
            temp->count=counter;
            addNode(temp,counter);
            
            
        }
        else{
            if(cap==capacityCounter){
                if(keyAddMap.size()!=0){
                    auto it=counterLinkedListMap.begin();
                    Node *deleteTail=it->second.second;
                    int itsKey=deleteTail->prev->key;
                    deleteNode(deleteTail->prev,it->first);
                    keyAddMap.erase(itsKey);
                }

            }
            Node* newNode=new Node(key,value);
            keyAddMap[key]=newNode;
            int counter=newNode->count;
            addNode(newNode,counter);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */