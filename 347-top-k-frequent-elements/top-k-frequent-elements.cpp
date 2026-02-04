class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> ans;
        for (auto &[n, c] : cnt) ans.push_back(n);
        if (ans.size() == k) return ans;
        auto partition = [&](int L, int R) {
            int i = L, j = L, pivotIndex = L + rand() % (R - L + 1), pivot = cnt[ans[pivotIndex]];
            swap(ans[pivotIndex], ans[R]);
            for (; i < R; ++i) {
                if (cnt[ans[i]] > pivot) swap(ans[i], ans[j++]);
            }
            swap(ans[j], ans[R]);
            return j;
        };
        auto quickSelect = [&](int k) {
            int L = 0, R = ans.size() - 1;
            while (L < R) {
                int M = partition(L, R);
                if (M + 1 == k) break;
                if (M + 1 > k) R = M - 1;
                else L = M + 1;
            }
        };
        quickSelect(k);
        ans.resize(k);
        return ans;
    }
};