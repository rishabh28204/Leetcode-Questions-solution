class Solution {
public:
    void helper(vector<int> &v,set<vector<int>> &ans,int i,vector<int> nums)
    {
      if(i>=nums.size())
      {
        if(v.size()>=2)
        ans.insert(v);
        return;
      }
      if(!v.size()||nums[i]>=v.back())
      {
        v.push_back(nums[i]);
        helper(v,ans,i+1,nums);
        v.pop_back();

      }
      helper(v,ans,i+1,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ans;
        helper(ans,st,0,nums);
        return vector(st.begin(),st.end());
    }
};
