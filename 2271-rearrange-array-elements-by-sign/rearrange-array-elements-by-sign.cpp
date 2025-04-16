class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0); //
        int positiveIndex = 0;
        int negativeIndex = 1;
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[positiveIndex] = nums[i];
               // ans.push_back(nums[i]);
                positiveIndex +=2;
            }
            else{
                ans[negativeIndex] = nums[i];
                //ans.push_back(nums[i]);
                negativeIndex +=2;
            }
        }
        return ans;
    }
};