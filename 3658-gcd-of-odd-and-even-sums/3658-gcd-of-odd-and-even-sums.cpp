class Solution {
public:

    int gcd(int sumOdd, int sumEven){
        return __gcd(sumOdd, sumEven);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*(n+1);
        int ans = gcd(sumOdd, sumEven);
        return ans;
    }
};