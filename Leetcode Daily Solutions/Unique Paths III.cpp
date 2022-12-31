// Backtracking & DFS

class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>& grid,int n,int m,int tillcnt,int &cnt,int &ans)
    {
      if(i<0||i>=m||j<0||j>=n) return ;
      if(grid[i][j]==-1)return ;
      if(grid[i][j]==2)
      {
        cout<<tillcnt<<" "<<cnt<<endl;
        if(tillcnt-1==cnt)
        {
          ans++;
        }
          return ;
      }
        grid[i][j]=-1;
        // if(i>=0&&i<m&&j>=0&&j<m){
        dfs(i-1,j,grid,n,m,tillcnt+1,cnt,ans);
        dfs(i+1,j,grid,n,m,tillcnt+1,cnt,ans);
        dfs(i,j-1,grid,n,m,tillcnt+1,cnt,ans);
        dfs(i,j+1,grid,n,m,tillcnt+1,cnt,ans);
        // }
        
        grid[i][j]=0;
        // return;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt=0;
        int startx,starty;
        int n=grid[0].size();
        int m=grid.size();
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[0].size();j++)
          {
            if(grid[i][j]==0)cnt++;
            else if(grid[i][j]==1)
            {
              startx=i;
              starty=j;
            }
          }
        }
        // cout<<startx<<" "<<cnt<<endl;
        int ans=0,tillcnt=0;
        dfs(startx,starty,grid,n,m,tillcnt,cnt,ans);
        return ans;
    }
};
