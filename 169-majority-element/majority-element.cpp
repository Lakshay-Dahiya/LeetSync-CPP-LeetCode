class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // better solution
        map<int,int> mpp;
        int n = nums.size();
        // nlogn
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        //n 
        //total tc : o(nlogn) + o(n)
        // sc: o(n)
        for(auto it: mpp){
            if(it.second > (n/2)) return it.first;
        }
        return -1;
    }
};