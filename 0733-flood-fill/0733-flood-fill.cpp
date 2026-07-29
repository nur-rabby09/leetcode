class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }

        int oldColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size(); 
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        visited[sr][sc] = true;
        q.push({sr, sc});
        image[sr][sc]=color;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second; 
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                visited[nrow][ncol]==false && image[nrow][ncol]==oldColor){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                    image[nrow][ncol]=color;
                }
            }
        }

        return image;
    }
};