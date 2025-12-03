/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy=new ListNode(-1);
    ListNode* ansIterator=dummy;
    int carry=0;
    int sum=0;
    ListNode* temp1=l1;
    ListNode* temp2=l2;
    while(temp1!=NULL || temp2!=NULL){
        sum=carry;
        if(temp1!=NULL){
            sum=sum+temp1->val;
            temp1=temp1->next;
        }
        if(temp2!=NULL){
            sum=sum+temp2->val;
            temp2=temp2->next;
        }
        ListNode* newNode=new ListNode(sum%10);
        carry=sum/10;
        ansIterator->next=newNode;
        ansIterator=ansIterator->next;
    }
    if(carry) ansIterator->next=new ListNode(carry);
    return dummy->next;
    }
};