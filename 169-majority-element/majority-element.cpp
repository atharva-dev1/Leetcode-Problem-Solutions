class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto n : nums){
            mp[n]++;
        }
        int res = INT_MIN, ans;
        for(auto n : nums){
            if(res < mp[n]){
                res = mp[n];
                ans = n;
            }

        }
        return ans;
    }
};