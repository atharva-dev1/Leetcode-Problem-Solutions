class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        // dist[used][i][j]
        vector<vector<vector<int>>> dist(
            k + 1, vector<vector<int>>(m, vector<int>(n, INF))
        );

        // All cells sorted by grid value
        vector<pair<int,int>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({i, j});

        sort(cells.begin(), cells.end(), [&](auto &a, auto &b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        });

        // For each teleport count, pointer to next teleportable cell
        vector<int> ptr(k + 1, 0);

        // Min-heap: {cost, row, col, usedTeleports}
        priority_queue<
            array<int,4>,
            vector<array<int,4>>,
            greater<>
        > pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        while (!pq.empty()) {
            auto [cost, r, c, used] = pq.top();
            pq.pop();

            if (cost != dist[used][r][c]) continue;

            // Reached destination
            if (r == m - 1 && c == n - 1)
                return cost;

            // Move right
            if (c + 1 < n) {
                int nc = cost + grid[r][c + 1];
                if (nc < dist[used][r][c + 1]) {
                    dist[used][r][c + 1] = nc;
                    pq.push({nc, r, c + 1, used});
                }
            }

            // Move down
            if (r + 1 < m) {
                int nc = cost + grid[r + 1][c];
                if (nc < dist[used][r + 1][c]) {
                    dist[used][r + 1][c] = nc;
                    pq.push({nc, r + 1, c, used});
                }
            }

            // Teleport (optimized)
            if (used < k) {
                int val = grid[r][c];
                int &p = ptr[used];

                while (p < cells.size() &&
                       grid[cells[p].first][cells[p].second] <= val) {
                    int x = cells[p].first;
                    int y = cells[p].second;
                    if (cost < dist[used + 1][x][y]) {
                        dist[used + 1][x][y] = cost;
                        pq.push({cost, x, y, used + 1});
                    }
                    p++;
                }
            }
        }

        return -1;
    }
};
