class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0, col = 0;
        for (string &cmd : commands) {
            if (cmd == "RIGHT") col++;
            else if (cmd == "LEFT") col--;
            else if (cmd == "DOWN") row++;
            else if (cmd == "UP") row--;
        }
        return row * n + col;
    }
};