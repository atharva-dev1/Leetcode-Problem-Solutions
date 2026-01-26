class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> merg;
        int i = 0 , j = 0 ;
        int m = nums1.size() , n = nums2.size();

        while ( i < m  &&  j < n){
            if (nums1[i] < nums2[j]){
                merg.push_back(nums1[i]);
                i++;
            }
            else{
                merg.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m ){
            merg.push_back(nums1[i]);
            i++;
        }
        while (j < n){
            merg.push_back(nums2[j]);
            j++;
        }
        int res = merg.size();
        if(res % 2  == 1 ){
            return (double)merg[res / 2];
        }
        else{
            return (merg[res / 2 - 1]+ merg[res / 2]) / 2.0;
        }
    }
};