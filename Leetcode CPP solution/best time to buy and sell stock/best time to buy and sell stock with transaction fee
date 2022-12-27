class Solution {
public:
    // int helper(vector<int> &prices,int fee,int buy,int i,vector<vector<int>>&dp)
    // {
    //     if(i==prices.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[i][buy]!=-1)
    //     return dp[i][buy];
    //     if(buy)
    //     return dp[i][buy]=max((-prices[i]+helper(prices,fee,0,i+1,dp)),(0+helper(prices,fee,1,i+1,dp)));
    //     else
    //     return dp[i][buy]=max(((prices[i]-fee)+helper(prices,fee,1,i+1,dp)),(0+helper(prices,fee,0,i+1,dp)));
        
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                    dp[i][buy]=max((-prices[i]+dp[i+1][0]),(0+dp[i+1][1]));
                else
                    dp[i][buy]=max(((prices[i]-fee)+dp[i+1][1]),(0+dp[i+1][0]));
            }
        }
        return dp[0][1];
    }
};
