class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    /*int n = nums.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum % k == 0) result++;
        }
    }
    return result;
}*/

/*int n = nums.size();
    vector<int> prefix(n+1, 0);333333333333
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + nums[i];
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int sum = prefix[j] - prefix[i];
            if (sum % k == 0) result++;
        }
    }
    return result;
    }*/
     unordered_map<int, int> count;
    count[0] = 1; 
    int prefixSum = 0, result = 0;
    
    for (int n : nums) {
        prefixSum += n;
        int rem = ((prefixSum % k) + k) %k; 
        result += count[rem];
        count[rem]++;
    }
    return result;
}
};