class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0 , j = 0 , k = 0;
        while(i<m){
            nums1[k++] = nums1[i++];
        }
        while(j<n){
            nums1[k++] = nums2[j++];
        }
        sort(nums1.begin(),nums1.end());
    }
};