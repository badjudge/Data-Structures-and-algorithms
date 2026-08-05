class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the adjacency list graph
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // Step 2: Use BFS to find all suspicious methods reachable from k
        vector<bool> isSuspicious(n, false);
        queue<int> q;
        
        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!isSuspicious[neighbor]) {
                    isSuspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Check if any non-suspicious method invokes a suspicious method
        bool canRemove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            // If an external method (u is safe) invokes a suspicious method (v is suspicious)
            if (!isSuspicious[u] && isSuspicious[v]) {
                canRemove = false;
                break;
            }
        }

        // Step 4: Construct the result vector
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (canRemove) {
                // Only keep safe methods
                if (!isSuspicious[i]) {
                    res.push_back(i);
                }
            } else {
                // If we can't remove anything, return all methods
                res.push_back(i);
            }
        }

        return res;
    }
};
