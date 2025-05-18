class Solution {
public:
    int minDivisor(vector<int>& nums, int divisor){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += (int)ceil((double) nums[i] / (double) divisor);
        }
        return sum;
    }
    int maxElement(vector<int>& nums){
        int n = nums.size();
        int maxi = nums[0];
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = maxElement(nums);
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(minDivisor(nums, mid) <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;   
        }
        return ans;
    }
};