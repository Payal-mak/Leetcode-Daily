#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        // Initialize a variable to serve as a bitmask where each bit represents
        // the count of '1's in the binary strings seen so far.
        int bitmask = 0;
      
        // Loop through the binary strings.
        for (auto& str : nums) {
            // Count the number of '1's in the current string.
            int countOnes = std::count(str.begin(), str.end(), '1');
            // Set the corresponding bit in the bitmask.
            bitmask |= 1 << countOnes;
        }
      
        // Loop indefinitely to find a binary string with a different count of '1's.
        for (int i = 0;; ++i) {
            // Check if the current count of '1's is not represented in the bitmask.
            // The expression (bitmask >> i) shifts the bitmask to the right by 'i' bits,
            // and then checks if the least significant bit is not set.
            if (((bitmask >> i) & 1) == 0) {
                // If not set, we found our number. Return a binary string with 'i' ones
                // followed by enough zeros to match the size of the input binary strings.
                return std::string(i, '1') + std::string(nums.size() - i, '0');
            }
        }
        // No return is needed here as the loop is guaranteed to return a string
        // because there are 2^N possible binary strings of length N, and only N of them
        // have unique counts of '1's, leaving at least one string that is different.
    }
};