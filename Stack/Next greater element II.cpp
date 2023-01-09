// https://leetcode.com/problems/next-greater-element-ii/submissions/874898512/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        st.push(nums[i]);

        for(int i=n-1;i>=0;i--)
        {
          while(!st.empty()&&nums[i]>=st.top())
          st.pop();

          if(st.size()==0)
          ans.push_back(-1);
          else
          {
              ans.push_back(st.top());
          }
          st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
