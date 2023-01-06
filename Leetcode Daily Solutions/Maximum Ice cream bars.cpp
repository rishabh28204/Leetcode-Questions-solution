class Solution {
public:
    int maxIceCream(vector<int>& v, int coins) {
        sort(v.begin(),v.end());
        int ans=0;
        int x=coins;
        for(int i=0;i<v.size();i++)
        {
          if(x>=v[i])
          {
            ans++;
            x-=v[i];
          }
        }
        return ans;
    }
};
