#include<bits/stdc++.h>
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
          int d=floor(log10(k) + 1);
        vector<int> dig(d);
        for(int i=d-1; i>=0;i--)
        {
            int x=k%10;
            dig[i]=x;
            k/=10;
        }
        int carry=0;
        vector<int> ans;
        reverse(num.begin(),num.end());
        reverse(dig.begin(),dig.end());
        int i=0;

        while(i<d&&i<num.size())
        {
          int x=num[i];
          x+=dig[i]+carry;
          if(x>=10)
          {
            carry=1;
            ans.push_back(x%10);
          }
          else{
          carry=0;
          ans.push_back(x);
           }
          i++;
          
        }
        if(i<num.size())
        {
          while(i<num.size())
          {
            int x=num[i]+carry;
            if(x>=10)
            {
              carry=1;
              ans.push_back(x%10);

            }
            else
            {
              carry=0;
              ans.push_back(x);
            }
            i++;
          }
        }
        // cout<<<<endl;
        while(i<dig.size())
        {
          cout<<i<<" ";
           int x=dig[i]+carry;
            if(x>=10)
            {
              carry=1;
              ans.push_back(x%10);

            }
            else
            {
              carry=0;
              ans.push_back(x);
            }
            i++;
          }
        
        if(carry)
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
