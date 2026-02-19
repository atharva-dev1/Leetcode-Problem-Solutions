class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int ans = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                // Skip duplicates
                continue;
            }
            if (nums[i] == nums[i-1] + 1) {
                currentStreak++;
            } else {
                currentStreak = 1;
            }
            ans = max(ans, currentStreak);
        }

        return ans;
    }
};