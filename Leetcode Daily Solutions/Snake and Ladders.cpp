// Using BFS 

class Solution {
public:
    pair<int,int> findcord(int curr,int n)
    {
      int r=n-((curr-1)/n)-1;
      int c=(curr-1)%n;
      if(r%2==n%2)
      return {r,n-1-c};
      return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int vis[n][n];
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(1);
        vis[n-1][0]=1;
        int steps=0;
        while(!q.empty())
        {
          int size=q.size();
          for(int i=0;i<size;i++)
          {
            int x=q.front();
            q.pop();
            if(x==n*n) return steps;
            for(int k=1;k<=6;k++)
            {
              if(k+x>n*n) break;
              pair<int,int> p=findcord(k+x,n);
              int r=p.first;
              int c=p.second;
              if(vis[r][c]!=0)continue;
              else
              {
                vis[r][c]=1;
                if(board[r][c]==-1)
                q.push(k+x);
                else
                q.push(board[r][c]);
              }

            }

          }
          steps++;
        }
        return -1;
    }
};
