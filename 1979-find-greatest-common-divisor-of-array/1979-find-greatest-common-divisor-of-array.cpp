class Solution {
public:
    int gcd(int a, int b){
        if(a == 0) return b;
        return gcd(b%a, a);
    }
    int findGCD(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
            }
            if(nums[i] < smallest){
                smallest = nums[i];
            }
        }
        return gcd(smallest, largest);
    }
};