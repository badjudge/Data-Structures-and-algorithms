class Solution {
public:
    // dp[i][a] tracks: index i, and player a (1 for Alice, 0 for Bob)
    int solve(vector<int>& stoneValue, int i, vector<vector<int>>& dp, int a) {
        // Base case: no stones left
        if (i >= stoneValue.size()) return 0;
        
        // Return cached result if already calculated
        if (dp[i][a] != INT_MAX) return dp[i][a];
        
        if (a == 1) { // Alice's turn: Maximize the score difference
            int max_val = INT_MIN;
            int current_sum = 0;
            
            // Try picking 1, 2, or 3 stones
            for (int x = 0; x < 3 && i + x < stoneValue.size(); ++x) {
                current_sum += stoneValue[i + x];
                // Alice adds her stones, then Bob plays at (i + x + 1)
                int result = current_sum + solve(stoneValue, i + x + 1, dp, 0);
                max_val = max(max_val, result);
            }
            return dp[i][a] = max_val;
        } 
        else { // Bob's turn: Minimize the score difference
            int min_val = INT_MAX;
            int current_sum = 0;
            
            for (int x = 0; x < 3 && i + x < stoneValue.size(); ++x) {
                current_sum += stoneValue[i + x];
                // Bob subtracts his stones, then Alice plays at (i + x + 1)
                int result = -current_sum + solve(stoneValue, i + x + 1, dp, 1);
                min_val = min(min_val, result);
            }
            return dp[i][a] = min_val;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // Initialize with INT_MAX to indicate unvisited states
        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
        
        int score_diff = solve(stoneValue, 0, dp, 1);
        
        if (score_diff > 0) return "Alice";
        if (score_diff < 0) return "Bob";
        return "Tie";
    }
};
