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
    ListNode* oddEvenList(ListNode* head) {
        int count=1;
        ListNode* odd=new ListNode(-1);
        ListNode* even=new ListNode(-1);
        ListNode* oddTemp=odd;
        ListNode* evenTemp=even;
        ListNode* ogTemp=head;
        while(ogTemp!=NULL){
            if(count%2){
                oddTemp->next=new ListNode(ogTemp->val);
                oddTemp=oddTemp->next;
            }
            else{
                evenTemp->next=new ListNode(ogTemp->val);
                evenTemp=evenTemp->next;
            }
            ogTemp=ogTemp->next;
            count++;
        }
        even=even->next;
        oddTemp->next=even;
        return odd->next;
    }
};