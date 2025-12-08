/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* first=head;
        Node* second=head;
        int flag=0;
        while(second!=NULL && second->next!=NULL){
            second=second->next->next;
            first=first->next;
            if(first==second) {flag=1; break;}
        }
        if(flag!=1) return 0;
        Node* temp=first;
        first=first->next;
        int count=1;
        while(first!=temp && first!=NULL){
            count++;
            first=first->next;
        }
        return count;
    }
};