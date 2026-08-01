/**
 * @param {number[]} arr
 * @return {number}
 */
var sumOddLengthSubarrays = function(arr) {
    let total_sum = 0;
    const n = arr.length;
    for(let i = 0; i<n; i++){
        let sum = 0;
        for(let j = i; j<n; j++){
            sum += arr[j];
            if((j-i+1)%2 != 0){
                total_sum += sum;
            }
        }
    }
    return total_sum;
};