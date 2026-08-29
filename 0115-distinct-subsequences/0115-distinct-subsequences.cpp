class Solution {
public:
    int solve(string &s, string &t,int i,int j,vector<vector<int>> &dp){
        if( j>=t.size()) return 1;
        if(i>=s.size()) return 0;
        if(s[i]==t[j]){
            int tk=solve(s,t,i+1,j+1,dp);
            int nt=solve(s,t,i+1,j,dp);
            return dp[i][j]=tk+nt;
        }else{
            return dp[i][j]=solve(s,t,i+1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(s.size()+1,vector<unsigned long long>(t.size()+1,0));
        //return solve(s,t,0,0,dp);
        for(int i=s.size();i>=0;i--) dp[i][t.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                if(s[i]==t[j]) dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
                else dp[i][j]=dp[i+1][j];
            }
        }
        return dp[0][0];

    }
};