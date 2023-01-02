class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]>=65&&word[0]<=90)
        {
          int ans=1;
          for(int i=1;i<word.size();i++)
          {
            if(word[i]>=65&&word[i]<=90)ans++;
          }
          if(ans==word.size())return true;
          ans=1;
          for(int i=1;i<word.size();i++)
          {
            if(word[i]>=97&&word[i]<=122)ans++;
          }
          if(ans==word.size())return true;
        }
        int ans=0;
        for(int i=0;i<word.size();i++)
        {
          if(word[i]>=97&&word[i]<=122)ans++;
        }
        if(ans==word.size())return true;
        return false;
    }
};
