class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
        result.push_back({}); // start with empty subset

        for (int num : nums) {
            int n = result.size();
            for (int i = 0; i < n; i++) {
                vector<int> newSubset = result[i];
                newSubset.push_back(num);
                result.push_back(newSubset);
            }
        }
        return result;
    }
};