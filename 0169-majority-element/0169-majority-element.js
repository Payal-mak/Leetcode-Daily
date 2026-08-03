/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let candidate = -1;
    let votes = 0;
    for(let i = 0; i<nums.length; i++){
        if(votes == 0){
            candidate = nums[i];
            // votes = 1;
        }
        if(nums[i] == candidate){
            votes++;
        }
        else{
            votes--;
        }
    }
    return candidate;
};