class Solution {
public:
    int product(int x) {
        int p = 1;
        while (x) {
            int digit = x%10;
            p *= digit;
            x /= 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            if (product(n) % t == 0)
                return n;
            n++;
        }
    }
};