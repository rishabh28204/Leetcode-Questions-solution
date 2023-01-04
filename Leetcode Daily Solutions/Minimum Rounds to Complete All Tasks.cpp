class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int  i=0;i<tasks.size();i++)
        {
          mp[tasks[i]]++;
        }
        int ans=0;
        for(auto it:mp)
        {
          cout<<it.first<<" "<<it.second<<endl;
          if(it.second==1){
            ans=-1;
            break;
          }
          if(it.second%3==0)
          ans+=it.second/3;
         else if(it.second%3==1)
          {
            if(it.second!=4)
            {
            // cout<<it.second<<endl;
              ans+=it.second/3+1;
            }
            else
            ans+=2;
          }
          else if(it.second%3==2)
          {
                ans+=it.second/3+1;
          }
          

        }
        return ans;
    }
};
