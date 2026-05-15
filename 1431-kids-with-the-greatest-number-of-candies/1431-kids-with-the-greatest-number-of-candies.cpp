class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n, false);
        int greatest = candies[0];
        //vector<int> greatestCandies(n);
        for(int i = 0; i < n; i++){
            if(candies[i] > greatest){
                greatest = candies[i];
            }
        }
        for(int i = 0; i < n; i++){
            //int check = candies[i]+extraCandies;
            //candies.at(i) = check;
            //greatestCandies.push_back(candies[i+1]);
            //int flag = candies[i];
            // if(candies[i] < greatest){
            //     res.push_back(false);
            // }
            // else{
            //     res.push_back(true);
            // }
            if(candies[i] + extraCandies >= greatest){
                res.at(i) = true;
            }
        }
        return res;
    }
};