#include<bits/stdc++.h>
class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(1000000);
        unordered_map<int,int>mp;

        for(int i=nums2.size()-1;i>=0;i--)
        {
          if(nums2[i]<st.top())
          {
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
          }
          else
          {
            // cout<<nums2[i]<<st.top();
            while(nums2[i]>st.top())
            {
              st.pop();
            }
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
          }
          
        }
     
      for(int i=0;i<nums1.size();i++)
      {
          auto it=mp.find(nums1[i]);
          int x=it->second;
          if(x==1000000)
          x=-1;
          
          nums1[i]=x;
      }
      return nums1;
    }
};
