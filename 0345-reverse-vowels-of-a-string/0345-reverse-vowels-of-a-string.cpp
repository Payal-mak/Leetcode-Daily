class Solution {
public:
    // Helper function to keep the code clean and prevent bugs
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            // Check current states using the helper function
            bool iIsVowel = isVowel(s[i]);
            bool jIsVowel = isVowel(s[j]);

            // Case 1: Both are vowels -> Swap them and move both pointers
            if (iIsVowel && jIsVowel) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            // Case 2: i is a vowel, but j is not -> Move j inward to find a vowel
            else if (iIsVowel && !jIsVowel) {
                j--;
            }
            // Case 3: j is a vowel, but i is not -> Move i inward to find a vowel
            else if (!iIsVowel && jIsVowel) {
                i++;
            }
            // Case 4: Both are consonants -> Move both pointers inward
            else {
                i++;
                j--;
            }
        }
        return s;
    }
};