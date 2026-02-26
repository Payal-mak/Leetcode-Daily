class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Traverse from right to left, ignoring the most significant bit
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 0) {
                // even → divide by 2
                steps += 1;
            } else {
                // odd → add 1, then divide by 2
                steps += 2;
                carry = 1;
            }
        }

        // If carry remains at the MSB, one extra step needed
        if (carry == 1)
            steps += 1;

        return steps;
    }
};