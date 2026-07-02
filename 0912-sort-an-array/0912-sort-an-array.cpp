class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int l = st;
        int r = mid + 1;

        while (l <= mid && r <= end) {
            if (nums[l] <= nums[r]) {
                temp.push_back(nums[l]);
                l++;
            } else {
                temp.push_back(nums[r]);
                r++;
            }
        }

        // Copy remaining elements from left half
        while (l <= mid) {
            temp.push_back(nums[l]);
            l++;
        }

        // Copy remaining elements from right half
        while (r <= end) {
            temp.push_back(nums[r]);
            r++;
        }

        // Copy merged elements back into nums
        for (int i = 0; i < temp.size(); i++) {
            nums[st + i] = temp[i];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};