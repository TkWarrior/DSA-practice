class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        
        //Brute force - time complexity O(n) space complexity O(n)
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        //better approach reduce the space complexity to O(1)
        int count=0;
        int index1 = n/2 - 1;
        int index2 = n/2;
        int index1ele = -1;
        int index2ele = -1;
        int i = 0 , j = 0 ;
        //merging 
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count == index1) index1ele = nums1[i];
                if(count == index2) index2ele = nums1[i];
                count++;
                i++;             
            }
            else{
                if(count == index1) index1ele = nums2[j];
                if(count == index2) index2ele = nums2[j];
                count++;
                j++;
            }
        }
        while(i<n1){
            if(count == index1) index1ele = nums1[i];
            if(count == index2) index2ele = nums1[i];
            count++;
            i++;
           
        }
        while(j<n2){
            if(count == index1) index1ele = nums2[j];
            if(count == index2) index2ele = nums2[j];
            count++;
            j++;
           
        }
        
        // now we will apply binary search here
        
        double median;
        if((n1+n2)%2==0){
            return double((double)index1ele + (double)index2ele)/2;
        }
        else{
             median = (double) index2ele;
        }
        return median;

    }
};