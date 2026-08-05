class Solution {
public:
    int solve(vector<int>& nums,int i,vector<vector<int>> &dp,int j){
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
         int lp=nums[i]-solve(nums,i+1,dp,j);
         int rp=nums[j]-solve(nums,i,dp,j-1);
         return dp[i][j]=max(lp,rp);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int res=solve(nums,0,dp,nums.size()-1);
        if(res<0) return false;
        return true;
    }
};