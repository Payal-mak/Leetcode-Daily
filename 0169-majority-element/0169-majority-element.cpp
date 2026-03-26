class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //optimal approach
        //moore voting algorithm
        int count = 0;
        int candidate = 0;

        for(int num : nums){
            if(count == 0){
                candidate = num; //if it is a new element, whose count is 0, candidate = num
            }
            //if it is the same element, then simply do count++
            if(num == candidate){
                count++;
            }
            //if it is different element, then decrement count
            else{
                count--;
            }
        }
        //If the majority element has more than n/2 occurrences:
        //The algorithm will ensure that the count remains positive for the majority element throughout the traversal, guaranteeing that it will be selected as the final candidate.
        return candidate;
    }
};