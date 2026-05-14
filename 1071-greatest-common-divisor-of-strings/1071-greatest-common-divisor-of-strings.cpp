class Solution {
public:
    int gcd(int a, int b){
        if(a == 0) return b;
        return gcd(b%a,  a);
    }
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)?
        str1.substr(0,gcd(size(str1), size(str2))):"";
    }
};