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
        if(lists.size()==0){
            return NULL;
        }
        
        priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>,greater<pair<int,ListNode*>>> q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
            q.push({lists[i]->val,lists[i]});}
        }
        ListNode *dummyNode=new ListNode(-1);
        ListNode *temp=dummyNode;
        while(!q.empty()){
            auto it=q.top();
            temp->next=it.second;
            temp=temp->next;
            q.pop();
            if(it.second->next!=nullptr){
                q.push({it.second->next->val,it.second->next});
            }
        }
    return dummyNode->next;
    }
};