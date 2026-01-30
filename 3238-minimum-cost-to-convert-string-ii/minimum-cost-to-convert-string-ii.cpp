class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        const long long INF = 1e18;
        int n = source.size();

        // 1️⃣ Collect all unique strings
        unordered_map<string, int> id;
        vector<string> all;

        auto add = [&](const string& s) {
            if (!id.count(s)) {
                id[s] = all.size();
                all.push_back(s);
            }
        };

        for (int i = 0; i < original.size(); i++) {
            add(original[i]);
            add(changed[i]);
        }

        int S = all.size();

        // 2️⃣ Build distance matrix for substrings
        vector<vector<long long>> dist(S, vector<long long>(S, INF));
        for (int i = 0; i < S; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // 3️⃣ Floyd–Warshall on substrings
        for (int k = 0; k < S; k++)
            for (int i = 0; i < S; i++)
                for (int j = 0; j < S; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // 4️⃣ DP over source string
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // Case 1: single character
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Case 2: substring transformations
            for (int a = 0; a < S; a++) {
                const string& from = all[a];
                int len = from.size();

                if (i + len > n) continue;

                if (source.compare(i, len, from) != 0) continue;

                for (int b = 0; b < S; b++) {
                    if (dist[a][b] == INF) continue;
                    const string& to = all[b];

                    if (to.size() != len) continue;
                    if (target.compare(i, len, to) != 0) continue;

                    dp[i + len] = min(dp[i + len], dp[i] + dist[a][b]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
