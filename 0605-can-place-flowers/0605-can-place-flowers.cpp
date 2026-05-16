class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int count = 0;
        int i = 0;

        while(i < s){
            if(flowerbed[i] == 1){
                i += 2;
            }
            //flowerbed[i] == 0
            else{
                if((i== 0 || flowerbed[i-1] == 0) && (i == s-1 || flowerbed[i+1] == 0)){
                    count++;
                    i += 2;
                }
                else{
                    i++;
                }
            }
        }
        if(count >= n){
            return true;
        }else{
            return false;
        }
    }
};