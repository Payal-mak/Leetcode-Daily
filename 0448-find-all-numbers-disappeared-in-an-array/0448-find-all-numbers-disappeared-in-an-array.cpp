#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        //this copies the elements of vectors into set
        //this removes duplicates, and sorts the array
        set<int> set_nums(nums.begin(), nums.end());
        //this vector will store the missing numbers
        vector<int> miss;

        //we loop from 1->n
        for(int i = 1; i <= nums.size(); i++){
            //if i is not present in the set
            if(set_nums.find(i) == set_nums.end()){
                //push the missing element in miss
                miss.push_back(i);
            }
        }

        return miss;
    }
};