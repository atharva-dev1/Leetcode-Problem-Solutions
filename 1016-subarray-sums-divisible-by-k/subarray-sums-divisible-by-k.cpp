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
unordered_map<int , int> mp ;
mp[0] = 1;
int sum = 0  , count = 0  ;
for( int i = 0 ; i < nums.size() ; i++){
    sum = sum + nums[i];
    int rem = sum % k ;
    if (rem < 0 ){
        rem = rem + k;
    }
     if (mp.count(rem)){
        count = count + mp[rem];
     }
         mp[rem]++;
     }
     return count;
    }
};