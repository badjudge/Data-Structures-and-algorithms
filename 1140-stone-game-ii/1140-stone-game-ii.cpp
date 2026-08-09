#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // 3D memoization array because the state depends on: i, M, and the current player (implied by minimax)
    // Constraints: piles.size() <= 100, M max is around 100
    int dp[101][101];

    int dfs(vector<int>& piles, int i, int M) {
        // Base Case: If we have reached or passed the end of the piles, no more stones can be taken
        if (i >= piles.size()) {
            return 0;
        }

        // If this state has already been calculated, return the cached result
        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        // If the current player can take all the remaining piles, they should take them all
        if (i + 2 * M >= piles.size()) {
            return piles.back() - (i > 0 ? piles[i - 1] : 0);
        }

        int max_stones = INT_MIN;

        // The player can choose to take X piles, where 1 <= X <= 2M
        for (int x = 1; x <= 2 * M; x++) {
            // Calculate stones obtained from taking X piles using the prefix sum
            int current_take = piles[i + x - 1] - (i > 0 ? piles[i - 1] : 0);
            
            // Minimax logic: Current player gets (current_take) + (total remaining stones - what the opponent will optimally get)
            int total_remaining = piles.back() - piles[i + x - 1];
            int opponent_score = dfs(piles, i + x, max(M, x));
            
            int current_score = current_take + (total_remaining - opponent_score);
            
            max_stones = max(max_stones, current_score);
        }

        // Cache and return the result
        return dp[i][M] = max_stones;
    }

    int stoneGameII(vector<int>& piles) {
        // Convert piles into a prefix sum array to quickly calculate range sums
        for (int i = 1; i < piles.size(); i++) {
            piles[i] += piles[i - 1];
        }

        // Initialize the memoization table with -1
        for (int i = 0; i <= piles.size(); i++) {
            for (int j = 0; j <= piles.size(); j++) {
                dp[i][j] = -1;
            }
        }

        // Alice starts at index 0 with M = 1
        return dfs(piles, 0, 1);
    }
};
