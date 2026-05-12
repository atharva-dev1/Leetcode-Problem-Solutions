class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int res = 0;
    //     for(int i=0; i<n ; i++){
    //         for(int j=i+1; j<n; j++){
    //             res =max(res, (nums[i]-1) * (nums[j]-1));
    //         }
    //     }
    //     return res;
    // }
    int n = nums.size();
    int res = 0;
    sort(nums.begin(), nums.end());
    res = (nums[n-1]-1) * (nums[n-2]-1);
    return res;
    }

};