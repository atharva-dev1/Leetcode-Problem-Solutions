class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    freq[0] = 1; // base case
    int prefix = 0, count = 0;
    for (int num : nums) {
        prefix += num;
        int rem = ((prefix % k) + k) % k; // normalize remainder
        if (freq.count(rem)) count += freq[rem];
        freq[rem]++;
    }
    return count;

    }
};