class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long s=0, sn=0;
        long long s2=0, s2n=0;
        sn = (n * (n+1)) / 2;
        s2n = (n * (n+1) * (2*n+1)) / 6;

        for(int i=0; i<n; i++){
            s += nums[i];
            s2 += (long long)nums[i] * (long long)nums[i];
        }

        long long val1 = s - sn; // x-y
        long long val2 = (s2 - s2n) / val1; //x+y
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x,(int)y};

    }
};