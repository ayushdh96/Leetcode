/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
void inserIntoTheNode(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* nextElement=temp->next;
        Node* copy=new Node(temp->val);
        copy->next=nextElement;
        temp->next=copy;
        temp=nextElement;
    }
}

void insertRandomIntoTheNode(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* copy=temp->next;
        if(temp->random!=NULL){
            copy->random=temp->random->next;
        }
        else{
            copy->random=nullptr;
        }
        temp=temp->next->next;
    }
}
Node* getTheFinalList(Node* head){
    Node* dummy=new Node(-1);
    Node* temp=head;
    Node* res=dummy;
    while(temp!=NULL){
        res->next=temp->next;
        temp->next=temp->next->next;
        res=res->next;
        temp=temp->next;
        
    }
    return dummy->next;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        inserIntoTheNode(head);
        insertRandomIntoTheNode(head);
        return getTheFinalList(head);
    }
};