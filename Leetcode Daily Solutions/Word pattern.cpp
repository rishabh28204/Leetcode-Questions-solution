class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char>mp2;
        string wrd;
        stringstream str(s);
        int j=0;
        vector<string> v;
        while(str>>wrd)
        {
            v.push_back(wrd);
            j++;
        }
        if(pattern.size()!=j)return false;
        for(int i=0;i<pattern.size();i++)
        {
          if(mp1.find(pattern[i])==mp1.end())
          mp1[pattern[i]]=v[i];
          else
          {
            auto it=mp1.find(pattern[i]);
            if(it->second!=v[i])return false;
          }

          if(mp2.find(v[i])==mp2.end())
          mp2[v[i]]=pattern[i];
          else
          {
            auto it=mp2.find(v[i]);
            if(it->second!=pattern[i])
            return false;
          }
        }
        return true;
    }
};
