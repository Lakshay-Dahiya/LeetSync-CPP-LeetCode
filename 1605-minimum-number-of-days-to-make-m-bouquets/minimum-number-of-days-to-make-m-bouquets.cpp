class Solution {
public:
    int maxDay(vector<int>& bloomDay){
        int n = bloomDay.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(bloomDay[i] > maxi){
                maxi = bloomDay[i];
            }
        }
        return maxi;
    }
     int minDay(vector<int>& bloomDay){
        int n = bloomDay.size();
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            if(bloomDay[i] < mini){
                mini = bloomDay[i];
            }
        }
        return mini;
    }
    bool totalBouquetsPossible(vector<int>& bloomDay, int day, int m, int k){
        int counterr = 0;
        int n = bloomDay.size();
        int noOfBouq = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                counterr++;
            }
            else{
                noOfBouq += (counterr/k);
                counterr = 0;
            }
        }
        noOfBouq += (counterr/k);
        return noOfBouq >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long) m * (long long) k;
        if(val > bloomDay.size()) return -1;
        int low = minDay(bloomDay);
        int high = maxDay(bloomDay);

        while(low <= high){
            int mid = (low + high) / 2;
            bool possibleday = totalBouquetsPossible(bloomDay, mid, m, k);
            if(possibleday){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;  
    }
};