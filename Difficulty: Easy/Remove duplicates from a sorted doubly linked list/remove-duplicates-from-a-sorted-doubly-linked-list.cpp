/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp=head;
        Node* next;
        Node* prev=temp;
        temp=temp->next;
        while(temp!=NULL){
            if(prev->data==temp->data){
                next=temp->next;
                if(next!=NULL) next->prev=prev;
                if(prev!=NULL) prev->next=next;
                temp->next=NULL;
                temp->prev=NULL;
                temp=next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};