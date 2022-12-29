typedef pair<long long,pair<long long,long long>> pi;
class Solution {
public:
    vector<int> helper(vector<vector<int>> &tasks)
    {
        vector<pi> vp;
        for(long long i=0;i<tasks.size();i++)
        {
          long long x=tasks[i][0];
          long long y=tasks[i][1];
          vp.push_back({x,{y,i}});
        }
        sort(vp.begin(),vp.end());
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        long long i=0;
        vector<int> ans;
        long long finishtime=vp[0].first;
        long long k=vp.size();
        while(k)
        {
            while(i<vp.size()&&finishtime>=vp[i].first)
            {
              pq.push({vp[i].second.first,vp[i].second.second});
              i++;
            }
            
            auto [it1,it2]=pq.top();
            pq.pop();
            finishtime+=it1;
            ans.push_back(it2);


            if(pq.empty()&&(i<tasks.size()&&finishtime<vp[i].first))
            finishtime=vp[i].first;

            k--;
        }
        return ans;
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        return helper(tasks);
    }
};
