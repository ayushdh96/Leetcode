// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        Node* first=head;
        Node* second=head;
        while(second->next!=NULL){
            second=second->next;
        }
        if(head==NULL) return {};
        while(first->data<second->data){
            int value=first->data+second->data;
            if(value==target){
                ans.push_back({first->data,second->data});
                first=first->next;
                second=second->prev;
            }
            else if(value<target) first=first->next;
            else second=second->prev;
                
            }
            return ans;
        }
};