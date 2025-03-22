class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value){
            this->key=key;
            this->value=value;
            next=nullptr;
            prev=nullptr;
        }
    };
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap=0;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    map<int, Node *>mpp;
    
    void replaceTheString(Node* val){
        if (val->prev == head) return;
        Node* temp=head->next;
        Node* delprev=val->prev;
        Node* delnext=val->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        val->next=temp;
        val->prev=head;
        temp->prev=val;
        head->next=val;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node *val=mpp[key];
            replaceTheString(val);
            return val->value;
        }
        else return -1;
        
    }
    
    void put(int key, int value) {
        Node *tempVal;
        if(mpp.find(key)==mpp.end()){
            if (mpp.size() >= cap) {
        Node* toBeDeleted = tail->prev;
        mpp.erase(toBeDeleted->key);
        Node *previousNode=toBeDeleted->prev;
        previousNode->next=tail;
        tail->prev=previousNode;
        
    
}
            Node *val=new Node(key,value);
            Node *temp=head->next;
            val->next=temp;
            temp->prev=val;
            head->next=val;
            val->prev=head;
            mpp[key]=val;
            
        }
        else{
            Node *val=mpp[key];
            val->value=value;
            replaceTheString(val);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */