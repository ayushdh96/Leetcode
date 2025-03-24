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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummyNode=new ListNode(-1);
        ListNode *dNode=dummyNode;
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()>0){
            dNode->next=lists[0];
            for(int i=1;i<lists.size();i++){
                ListNode *temp=lists[i];
                dNode=dummyNode;
                ListNode *prev=dNode;
                dNode=dNode->next;
                while(dNode!=NULL && temp!=NULL){
                    if(temp->val<=dNode->val){
                        prev->next=temp;
                        prev=temp;
                        temp=temp->next;
                        prev->next=dNode;
                    }
                    else{
                        prev=dNode;
                        dNode=dNode->next;
                    }
                }
                prev->next = temp ? temp : dNode;
            }
            return dummyNode->next;
        }
        return NULL;
    }
};