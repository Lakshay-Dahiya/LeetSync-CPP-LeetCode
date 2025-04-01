class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maximum = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            //int sum = 0; we don't want sum everytime 0
            sum += nums[i];
            maximum = max(sum,maximum);
            if(sum<0){
                sum = 0;
            }
        }
        return maximum;
    }
};