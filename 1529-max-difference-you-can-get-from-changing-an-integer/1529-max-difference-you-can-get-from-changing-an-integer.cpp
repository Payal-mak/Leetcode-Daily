class Solution {
public:
    // Function to replace all occurrences of a character 'from' with 'to' in a string 's'
    void replaceAll(std::string& s, char from, char to) {
        for (char& c : s) {
            if (c == from) {
                c = to;
            }
        }
    }
  
    // Function to calculate the maximum difference between two numbers you can get
    // by changing digits of the original number 'num'
    int maxDiff(int num) {
        // Convert the number to a string for easy manipulation
        std::string highestNumStr = std::to_string(num);
        std::string lowestNumStr = highestNumStr;
      
        // Crete the highest possible number by replacing the first non '9' digit with '9'
        for (int i = 0; i < highestNumStr.size(); ++i) {
            if (highestNumStr[i] != '9') {
                replaceAll(highestNumStr, highestNumStr[i], '9');
                break;
            }
        }
      
        // Create the lowest possible number
        if (lowestNumStr[0] != '1') {
            // If the first digit is not '1', replace it with '1'
            replaceAll(lowestNumStr, lowestNumStr[0], '1');
        } else {
            // If the first digit is '1', find the next digit that is not '0' or '1' and replace it with '0'
            for (int i = 1; i < lowestNumStr.size(); ++i) {
                if (lowestNumStr[i] != '0' && lowestNumStr[i] != '1') {
                    replaceAll(lowestNumStr, lowestNumStr[i], '0');
                    break;
                }
            }
        }
      
        // Convert the modified strings back to integers and return the difference
        return std::stoi(highestNumStr) - std::stoi(lowestNumStr);
    }
};
