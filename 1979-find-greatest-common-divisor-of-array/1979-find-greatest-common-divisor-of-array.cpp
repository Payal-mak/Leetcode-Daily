class Solution {
public:

    int gcd_of_two(int smallest, int largest){
        // int gcdd = 1;
        // largest = largest % smallest;
        // if(smallest == 0) gcdd = largest;
        // else gcdd = smallest;
        // return gcdd;
        return __gcd(smallest, largest);
    }    
    int findGCD(vector<int>& nums) {
        int smallest = nums[0];
        int largest = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < smallest){
                smallest = nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
            }
        }
        int ans = gcd_of_two(smallest, largest);
        return ans;
    }
};