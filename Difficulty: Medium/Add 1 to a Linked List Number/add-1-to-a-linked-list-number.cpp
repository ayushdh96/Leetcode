/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverseList(Node* head) {
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        if(head==NULL) return head;
        Node* newHead=reverseList(head);
        Node* temp=newHead;
        int value= (temp->data+1);
        int carry=value/10;
        temp->data=value%10;
        Node* preStop;
        if(temp->next==NULL) preStop=temp;
        temp=temp->next;
        while(temp!=NULL){
            value=carry+temp->data;
            carry=value/10;
            temp->data=value%10;
            if(temp->next==NULL || carry==0) {
                preStop=temp;
                break;
            }
            temp=temp->next;
        }
        if(carry!=0){
            Node* newNode=new Node(carry);
            preStop->next=newNode;
             
        }
        return reverseList(newHead);
        
        
        
        // return head of list after adding one
    }
};