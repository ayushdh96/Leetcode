class Disjoint{
    vector<int> size,parent;
    public:
    Disjoint(int v){
        parent.resize(v);
        size.resize(v);
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]){
            return parent[node];
        }
        return parent[node]=findParent(parent[node]);
        
    }
    void unionBySize(int left, int right){
        int leftParent=findParent(left);
        int rightParent=findParent(right);
        if(leftParent==rightParent){
            return;
        }
        if(size[leftParent]<size[rightParent]){
            size[rightParent]+=size[leftParent];
            parent[leftParent]=parent[rightParent];
        }
        else{
            size[leftParent]+=size[rightParent];
            parent[rightParent]=parent[leftParent];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int v=accounts.size();
        unordered_map<string,int> mpp;
        Disjoint dj(v);
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string currId=accounts[i][j];
                if(mpp.find(currId)==mpp.end()){
                    mpp[currId]=i;
                }
                else{
                    dj.unionBySize(i,mpp[currId]);
                }
            }
        }
        vector<vector<string>> emailId(v);
        for(auto it:mpp){
            string mpEmail=it.first;
            int mpNode=it.second;
            emailId[dj.findParent(mpNode)].push_back(mpEmail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<emailId.size();i++){
            if (emailId[i].empty()) continue;  
            sort(emailId[i].begin(),emailId[i].end());
            emailId[i].insert(emailId[i].begin(), accounts[i][0]);
            ans.push_back(emailId[i]);
        }
        return ans;
    }
};