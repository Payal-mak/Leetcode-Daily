/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let l = 0;
    let r = height.length-1;
    let area = 0;
    while(l < r){
        let diff = r-l;
        let h = Math.min(height[l], height[r]);

        area = Math.max(diff * h, area);
        if(height[l] < height[r]){
            l++;
        }
        else r--;
    }    
    return area;
};