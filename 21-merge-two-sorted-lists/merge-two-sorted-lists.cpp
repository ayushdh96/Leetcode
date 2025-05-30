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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyNode=new ListNode(-1);
        ListNode *temp1=list1;
        ListNode *temp2=list2;
        ListNode *t=dummyNode;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                t->next=temp1;
                t=temp1;
                temp1=temp1->next;

            }
            else{
                t->next=temp2;
                t=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL){
            t->next=temp1;
        }
        else if(temp2!=NULL){
            t->next=temp2;
        }
        return dummyNode->next;
    }
};