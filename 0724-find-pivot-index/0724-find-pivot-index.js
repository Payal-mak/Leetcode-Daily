/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    const n = nums.length;
    const prefixSum = [];
    const suffixSum = [];
    prefixSum[0] = 0;
    for(let i = 1; i<n; i++){
        prefixSum[i] = nums[i-1] + prefixSum[i-1];
    }
    suffixSum[n-1] = 0;
    for(let i = n-2; i>=0; i--){
        suffixSum[i] = nums[i+1] + suffixSum[i+1];
    }
    for(let i = 0; i < n; i++){
        if(prefixSum[i] == suffixSum[i]){
            return i;
        }
    }
    return -1;
};