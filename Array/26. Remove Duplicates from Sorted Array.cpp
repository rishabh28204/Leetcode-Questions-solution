// Without using extraspace O(N) time complexity

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=1,j=1;
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i]!=nums[i-1])
           {
             nums[j]=nums[i];
             j++;
           }
        }
        // sort(nums.begin(),nums.end());
        return j;


    }
};
