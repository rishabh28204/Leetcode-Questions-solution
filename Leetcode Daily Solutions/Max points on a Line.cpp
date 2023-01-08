class Solution {
public:
const double pi=3.141592653589793238;
    int maxPoints(vector<vector<int>>& points) {
        map<double,int> mp,mp2;
        // unordered_map<int,int> ans1;
        int ans=2;
      vector<pair<int,int>> vp;
      if(points.size()==1||points.size()==2)return points.size();
      int f1=0;
        for(int i=0;i<points.size();i++)
        {
          int x=points[i][0];
          int y=points[i][1];
          vp.push_back({x,y});
          // ans1[x]++;
        }
        // if(ans1.size()==1)return vp.size();
        
        for(int i=0;i<vp.size();i++)
        {
          int x1=vp[i].first;
          int y1=vp[i].second;
          // int f=0;
          for(int j=i+1;j<vp.size();j++)
          {
            // if(i==j)continue;
              int x2=vp[j].first;
              int y2=vp[j].second;
          int cnt=2;
              for(int k=0;k<vp.size();k++)
              {
                int x=vp[k].first,y=vp[k].second;
                if(k!=i&&k!=j)
                {
                  if((y-y1)*(x2-x1)==(x-x1)*(y2-y1))
                  cnt++;
                }
              }
              ans=max(ans,cnt);
              
          }
        }
      
       return ans;
    }
};
