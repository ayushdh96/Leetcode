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
    ListNode* mergeList(ListNode* left,ListNode* right){
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        if(left!=NULL) temp->next=left;
        else if(right!=NULL) temp->next=right;
        return dummy->next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* first=head;
        ListNode* second=head->next;
        while(second!=NULL && second->next!=NULL){
            first=first->next;
            second=second->next->next;
        }
        return first;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* middle=findMiddle(temp);
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* left=sortList(temp);
        right=sortList(right);
        return mergeList(left,right);
    }
};