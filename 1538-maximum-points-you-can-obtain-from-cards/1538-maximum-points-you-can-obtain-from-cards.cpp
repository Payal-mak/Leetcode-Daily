#include<bits/stdc++.h>
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        //we can pick consecutive cards either from the front or from the back
        //but the total number of cards you can pick is k
        int lsum = 0;
        int rsum = 0;
        //int maxSum = 0;
        //for the first window, considering from the left side
        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
            //considering it the maximum points
        }
        int maxSum = lsum;
        //shrinking cards one by one from the left and adding cards from the right
        int rightIdx = n - 1;
        for(int i = k-1; i >= 0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIdx];
            //taking more cards from the right
            rightIdx--;
            
            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};