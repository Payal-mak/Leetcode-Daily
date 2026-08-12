class Solution {
public:
    int canShip(vector<int> &weights, int days, int cap){
        int cnt = 0;
        int day = 1;
        int i = 0;
        while(i < weights.size()){
            if(cnt + weights[i] > cap){
                day++;
                cnt = 0;
            }
            cnt += weights[i];
            i++;
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int minW = 0;
        int maxW = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            minW = max(minW, weights[i]);
        }
        maxW = sum;
        while(minW < maxW){
            int mid = minW + (maxW - minW) / 2;
            if(canShip(weights, days, mid) <= days){
                maxW = mid;
            }
            else{
                minW = mid + 1;
            }
        }
        return minW;
    }
};