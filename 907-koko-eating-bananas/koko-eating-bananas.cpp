class Solution {
public:
    int maxElement(vector<int>& piles){
        int n = piles.size();
        int maxi = piles[0];
        for(int i=0; i<n; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    double calcTotalHours(vector<int>& piles, int hourly){
        double totalHrs = 0;
        int n = piles.size();
        for(int i=0; i<n; i++){
            totalHrs += (int) ceil((double)piles[i] / (double)hourly);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxElement(piles);
        while(low <= high){
            int mid = (low + high) / 2;
            double totalHrs = calcTotalHours(piles,mid);
            if(totalHrs <= h){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low; //changes polarity i.e. becomes ans 
    }
};