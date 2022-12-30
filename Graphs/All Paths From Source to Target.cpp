
/*Approach:
BackTracking Approach: as I have simply used DFS here taken an ans1 vector and 
for tracking the path to the destination if the node is equal to destination then 
push that vector in main ans and inside for loop after completing the call poped 
value of that perticular node(backtracking) and moved to next path.basically we 
have to pop ans1 after each call so we keep track of another path.
Complexity:
Time Complexity: O(2^N)
Space Complexity: O(N)
Code:
*/
class Solution {
public:

    void helper(vector<vector<int>>& graph,int node,vector<vector<int>> &ans,vector<int>&ans1,int dest)
    {
        // vis[node]=1;
        ans1.push_back(node);
        for(auto j:graph[node])
        {
          if(j==dest)
          {
            ans1.push_back(dest);
            ans.push_back(ans1);
            ans1.pop_back();
            continue;
          }      
            helper(graph,j,ans,ans1,dest);        
          ans1.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      // vector<int> vis(graph.size(),0),ans1;
      vector<vector<int>> ans;
      int dest=graph.size()-1;
      helper(graph,0,ans,ans1,dest);
      return ans;

      
        
    }
};
