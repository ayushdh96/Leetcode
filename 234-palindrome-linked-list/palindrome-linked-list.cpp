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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev;
        ListNode* next;

        if(temp==NULL || temp->next==NULL){
            return temp;
        }
        else{
            prev=temp;
            temp=temp->next;
            prev->next=NULL;
            if(temp->next!=NULL) next=temp->next;
            else {
                temp->next=prev;
                return temp;
                }
        }
        while(next->next!=NULL){
            temp->next=prev;
            prev=temp;
            temp=next;
            next=next->next;
        }
        temp->next=prev;
        next->next=temp;

        return next;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* first=temp;
        ListNode* second=temp;
        if(head==NULL || head->next==NULL) return head;
        while(second->next!=NULL && second->next->next!=NULL){
            first=first->next;
            second=second->next->next;
        }
        ListNode* newSecond=reverseList(first->next);
        while(newSecond!=NULL){
            if(temp->val!=newSecond->val) return false;
            temp=temp->next;
            newSecond=newSecond->next;
        }
        ListNode* reverse=reverseList(first->next);
        return true;
    }
};