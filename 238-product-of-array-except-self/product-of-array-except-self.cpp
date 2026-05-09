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

     int total = 1;
        int zeroCount = 0;

        for(int num : nums) {
            if(num == 0)
                zeroCount++;
            else
                total *= num;
        }

        vector<int> ans;

        for(int num : nums) {
            if(zeroCount > 1) {
                ans.push_back(0);
            }
            else if(zeroCount == 1) {
                if(num == 0)
                    ans.push_back(total);
                else
                    ans.push_back(0);
            }
            else {
                ans.push_back(total / num);
            }
        }

        return ans;
    }
};