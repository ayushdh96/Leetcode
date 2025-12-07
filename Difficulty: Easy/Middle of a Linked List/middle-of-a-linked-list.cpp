/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // code here
        if(head==NULL) return 0;
        Node* first=head;
        Node* second=head;
        while(second->next!=NULL && second->next->next!=NULL){
            first=first->next;
            second=second->next->next;
        }
        if(second->next==NULL) return first->data;
        return first->next->data;
        
    }
};