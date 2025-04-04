class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans;
        int i = 0 , j = 0 , k=0;
        //mergin 
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i++]) ;
                
            }
            else{
                ans.push_back(nums2[j++]);
               
            }
        }
        while(i<n1){
            ans.push_back(nums1[i++]);
           
        }
        while(j<n2){
            ans.push_back(nums2[j++]);
           
        }
        
        // now we will apply binary search here
        
        double mid = (n1+n2)/2;
        double median;
        if((n1+n2)%2==0){
            return double((double)ans[mid]+(double)ans[mid-1])/2;
        }
        else{
             median = ans[mid];
        }
        return median;

    }
};