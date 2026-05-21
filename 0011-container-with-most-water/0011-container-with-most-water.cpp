class Solution {
public:

    int area(vector<int>& height, int left, int right){
        return min(height[left], height[right]) * (right - left);
    }

    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int ans = 0;
        while(left < right){
            int currArea = area(height, left, right);
            ans = max(ans, currArea);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return ans;
    }
};