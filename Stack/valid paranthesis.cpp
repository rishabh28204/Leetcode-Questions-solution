class Solution {
public:
    bool ismatching(char a,char b)
    {
      if(a=='('&&b==')')return true;
      if(a=='{'&&b=='}')return true;
      if(a=='['&&b==']')return true;
      return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]=='('||s[i]=='{'||s[i]=='[')
          st.push(s[i]);
          else
          {
            if(st.size()==0)
            return false;
            cout<<st.top()<<s[i];
            if(ismatching(st.top(),s[i]))
            {
              st.pop();
              // continue;
            }
            else{
              return false;
            }
          }

        }
        if(st.size()==0)
        return true;
        return false;
    }
};
                                 
