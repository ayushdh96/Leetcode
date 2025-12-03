/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zero=new Node(-1);
        Node* one=new Node(-1);
        Node* two=new Node(-1);
        Node* zeroTemp=zero;
        Node* oneTemp=one;
        Node* twoTemp=two;
        Node* ogTemp=head;
        while(ogTemp){
            if(ogTemp->data==0){
                zeroTemp->next=new Node(0);
                zeroTemp=zeroTemp->next;
            }
            else if(ogTemp->data==1){
                oneTemp->next=new Node(1);
                oneTemp=oneTemp->next;
            }
            else{
                twoTemp->next=new Node(2);
                twoTemp=twoTemp->next;
            }
            ogTemp=ogTemp->next;
        }
        oneTemp->next=two->next;
        zeroTemp->next=one->next;
        return zero->next;
    }
};