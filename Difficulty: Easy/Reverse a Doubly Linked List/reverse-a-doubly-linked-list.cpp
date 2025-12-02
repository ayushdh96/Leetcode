/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* temp=head;
        while(temp!=NULL){
            Node* swap=temp->next;
            temp->next=temp->prev;
            temp->prev=swap;
            if(temp->prev==NULL) head=temp;
            temp=temp->prev;
        }
        return head;
    }
};