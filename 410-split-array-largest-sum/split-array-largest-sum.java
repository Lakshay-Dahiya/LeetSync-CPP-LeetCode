class Solution {
    public int splitArray(int[] nums, int k) {
         int start = 0;
        int end = 0;

        for(int i=0; i < nums.length ; i++){
            start = Math.max (start, nums[i]); //max value in the array
            end= end + nums[i];
        }
        while(start<end){
            int mid = start + (end - start)/2;

            int sum = 0;
            int pieces = 1;

            for(int num : nums){
                if(sum + num > mid){
                    sum = num;
                    pieces++;
                }
                else{
                    sum = sum + num;
                }
            }

            if(pieces>k){
                start = mid + 1; //target > mid then move right
            }
            else{
                end = mid ;
            }
        }
        return end; //here start==end at the end of the dry run
        
    }
}