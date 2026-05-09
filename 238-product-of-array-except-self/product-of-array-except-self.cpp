class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans(n, 1);

    //     for(int i = 0; i < n; i++) {
    //         int product = 1;

    //         for(int j = 0; j < n; j++) {
    //             if(i != j) {
    //                 product *= nums[j];
    //             }
    //         }

    //         ans[i] = product;
    //     }

    //     return ans;
    // }

    //  
    
     int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ans(n);

        prefix[0] = 1;

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        suffix[n - 1] = 1;

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};