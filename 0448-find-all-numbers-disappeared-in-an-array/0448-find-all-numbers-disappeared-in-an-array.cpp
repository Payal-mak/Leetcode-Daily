#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //loop through array
        for(int i = 0; i < nums.size(); i++){
            //take value and convert it to index
            //we take absolute value because
            int index = abs(nums[i])-1;

            //then mark it visited
            if(nums[index] > 0){
                nums[index] = -nums[index];
            }

        }
        //create a vector for storing the missing numbers
        vector<int> result;
        //loop through the array, if any element is positive, then it means
        //index+1 was never visited, hence it is missing
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                result.push_back(i+1);
            }
        }
        return result;
    }
};