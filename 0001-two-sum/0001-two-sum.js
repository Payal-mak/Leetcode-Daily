/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = new Map();
    const n=nums.length;
    for(let i=0;i<n;i++){
        let temp=target-nums[i];
        if(map.has(temp)){
            return [map.get(temp),i];
        }
        map.set(nums[i],i);
    }
    return [];
};