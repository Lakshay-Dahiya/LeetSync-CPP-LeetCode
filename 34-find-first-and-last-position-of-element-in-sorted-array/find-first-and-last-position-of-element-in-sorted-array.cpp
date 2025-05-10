class Solution {
public:

    int firstOccurrence(vector<int>& nums, int target){
        int n = nums.size();
        int first = -1;
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1; //nums[mid] > target
            }
        }
        return first;
    }

     int lastOccurrence(vector<int>& nums, int target){
        int n = nums.size();
        int last = -1;
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1; //nums[mid] < target
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums,target);
        if(first == -1) return {-1,-1};
        int last = lastOccurrence(nums,target);
        return{first, last};
    }
};