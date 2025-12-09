// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp=*head_ref;
        Node* prev=(*head_ref)->prev;
        Node* next;
        if(*head_ref==NULL) return;
        while(temp->data==x){
            next=temp->next;
            if(next!=NULL) next->prev=NULL;
            temp->next=NULL;
            temp=next;
        }
        *head_ref=temp;
        if(temp==NULL) return;
        while(temp!=NULL){
            if(x==temp->data){
                next=temp->next;
                if(next!=NULL) next->prev=prev;
                if(prev!=NULL) prev->next=next;
                temp->next=NULL;
                temp->prev=NULL;
                temp=next;
            }
            else {
                prev=temp;
                temp=temp->next;
            }
        }
    }
};