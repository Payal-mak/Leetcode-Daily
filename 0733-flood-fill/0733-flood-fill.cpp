class Solution {
public:

    void bfs(vector<vector<int>>& image, int i, int j, int color, int st){
        queue<pair<int, int>> q;
        q.push({i,j}); //push the current cell
        image[i][j] = color;
        vector<vector<int>> dirs = {
            {1, 0}, //down
            {0, 1}, //right
            {-1, 0},//up
            {0, -1} //left
        };

        if(st == color) return;
        while(!q.empty()){
            int si = q.front().first;
            int sj = q.front().second;

            q.pop(); 

            for(int k = 0; k < 4; k++){
                int f = si + dirs[k][0];
                int s = sj + dirs[k][1];

                if(f >= 0 && s >= 0 &&
                    f < image.size() && s < image[0].size() &&
                    image[f][s] == st)
                {
                    image[f][s] = color;
                    q.push({f,s});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        bfs(image, sr,sc,color, start);
        return image;
    }
};