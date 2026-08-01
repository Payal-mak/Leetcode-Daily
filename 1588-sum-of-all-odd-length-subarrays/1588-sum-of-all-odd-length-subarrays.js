/**
 * @param {number[]} arr
 * @return {number}
 */
var sumOddLengthSubarrays = function(arr) {
    const n = arr.length;
    const prefix = [];
    prefix[0] = arr[0];
    for(let i = 1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    // for(let i = 0; i<n; i++){
    //     console.log(prefix[i]);
    // }
    let ans = 0;
    for(let st = 0; st<n; st++){
        for(let end = st; end<n; end+=2){
            if(st === 0){
                ans += prefix[end];
            }
            else{
                ans += prefix[end] - prefix[st-1];
            }
        }
    }
    return ans;
};