class Solution {
public:
    void sortColors(vector<int>& nums) {
        //optimal approach
        //dnf algorithm
        //we will divide the whole array into four parts

        //0's -> 0 to low-1
        //1's -> low to mid-1
        //2's -> high+1 to n-1
        //unsorted -> mid to high
        int n = nums.size();
        int mid = 0, high = n-1, low = 0;
        //initially both low and mid pointers will point to the first element

        while(mid <= high){
            //for 0s
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            //for 1's
            else if(nums[mid] == 1){
                mid++;
            }
            //for 2's
            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        } 
    }
};