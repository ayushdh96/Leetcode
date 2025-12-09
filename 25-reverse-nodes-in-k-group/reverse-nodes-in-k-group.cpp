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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* next;
        ListNode* prev=NULL;
        while(temp!=NULL){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* tempHead=head;
        ListNode* prev=NULL;
        ListNode* next;
        int count=1;
        while(temp!=NULL){
            if(count==k){
                if(prev!=NULL) prev->next=NULL;
                next=temp->next;
                temp->next=NULL;
                ListNode* newHead=reverse(tempHead);
                if(prev!=NULL) prev->next=newHead;
                else head=newHead;
                tempHead->next=next;
                prev=tempHead;
                temp=next;
                tempHead=next;
                count=1;
            }
            else{
                count++;
                temp=temp->next;
            }
        }
        return head;
    }
};