class Solution {
public:
    void helper(vector<vector<int>>& isConnected,vector<bool>& visited,int src){
        visited[src]=true;
        for(int i=0;i<isConnected[src].size();i++){
            if(isConnected[src][i] && !visited[i]){
                
                helper(isConnected,visited,i);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int pro=0;
        pro++;
        helper(isConnected,visited,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                pro++;
                 helper(isConnected,visited,i);

            }
        }
        return pro;

        
    }
};