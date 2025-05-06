class Solution {
    private:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2){
        if(nums1[ind1] > nums2[ind2]){
            swap(nums1[ind1], nums2[ind2]);
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n;
        int gap = (len/2) + (len%2);
        while(gap>0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                // swap elements of arr1 and arr2
                if(left < m && right >= m){
                    swapIfGreater(nums1,nums2, left, right-m);
                }
                // swap elements of arr2 and arr2
                // right - m to access correct index of nums2

                else if(left >= m){
                    swapIfGreater(nums2,nums2, left-m, right-m);
                }

                // swap elements of arr1 and arr1
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }
                //else{
                    // skip if both in nums2 → no nee
                //}
                left++, right++;
            }
            if(gap==1) break;
            gap = (gap/2) + (gap%2);
        }
        //Copy nums2 into nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};