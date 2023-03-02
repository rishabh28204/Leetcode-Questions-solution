class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        for(int i=0;i<chars.size();)
        {
          char x=chars[i];
          s=s+x;
          int cnt=0;
          int j=i;
          while(j<chars.size())
          {
                if(chars[i]==chars[j])
                cnt++;
                else
                break;
                j++;
          }
          j=j-i;
          if(cnt>1){
          string y=to_string(cnt);
          s=s+y;}
          i=i+j;
        }
        int i=0;
        while(i<s.size())
        {
          chars[i]=s[i];
          i++;
        }
        return s.size();
    }
};
