// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

#include<bits/stdc++.h>
void sortStack(stack<int> &stack)
{
   
      std::stack<int> st;
    
      while(!stack.empty())
      {
          if(st.size()==0)
          {
              st.push(stack.top());
              stack.pop();
              continue;
          }
          if(stack.top()<=st.top())
          {
              st.push(stack.top());
              stack.pop();
          }
          else
          {
              int x=stack.top();
              stack.pop();
              while(!st.empty()&&x>st.top())
              {
                stack.push(st.top());
                  st.pop();
              }
              st.push(x);
          }
          
      }
    while(!st.empty())
    {
        stack.push(st.top());
        st.pop();
    }
                                                                                                                      
}
