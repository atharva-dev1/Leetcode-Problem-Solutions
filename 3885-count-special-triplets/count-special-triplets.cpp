class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> leftFreq, rightFreq;
        
        // Step 1: Fill rightFreq with all elements initially
        for (int num : nums) {
            rightFreq[num]++;
        }
        
        long long result = 0;
        
        // Step 2: Iterate through each index j
        for (int j = 0; j < nums.size(); j++) {
            // Remove nums[j] from right side (since j is the middle element now)
            rightFreq[nums[j]]--;
            
            long long leftCount = leftFreq[nums[j] * 2];
            long long rightCount = rightFreq[nums[j] * 2];
            
            // Contribution from this j
            result = (result + leftCount * rightCount) % MOD;
            
            // Add nums[j] to left side
            leftFreq[nums[j]]++;
        }
        
        return (int)result;
    }
};
