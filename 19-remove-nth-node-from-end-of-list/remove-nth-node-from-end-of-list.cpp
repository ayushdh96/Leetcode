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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* frontPointer=head;
        for(int i=1;i<=n;i++){
            frontPointer=frontPointer->next;
        }
        if(frontPointer==NULL) return head->next;
        ListNode* backPointer=head;
        while(frontPointer->next!=NULL){
            backPointer=backPointer->next;
            frontPointer=frontPointer->next;
        }
        if(backPointer->next==NULL){
            return head->next;
        }
        else{
            ListNode* temp=backPointer->next;
            backPointer->next=backPointer->next->next;
            temp->next=nullptr;
        }
        return head;
    }
};