class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();

        mpp[0] = 1; // {prefixSum,its-count}
        int prefixSum = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            count += mpp[remove];
            mpp[prefixSum] += 1;
        }
        return count;
    }
};