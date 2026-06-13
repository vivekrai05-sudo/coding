class Solution {
private:

    void bfs(int row,
             int col,
             vector<vector<int>> &vis,
             vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        // 4 directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int curRow = q.front().first;
            int curCol = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nRow = curRow + delRow[i];
                int nCol = curCol + delCol[i];

                if(nRow >= 0 &&
                   nRow < n &&
                   nCol >= 0 &&
                   nCol < m &&
                   grid[nRow][nCol] == '1' &&
                   !vis[nRow][nCol]) {

                    vis[nRow][nCol] = 1;

                    q.push({nRow, nCol});
                }
            }
        }
    }

public:

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                if(!vis[row][col] &&
                   grid[row][col] == '1') {

                    count++;

                    bfs(row, col, vis, grid);
                }
            }
        }

        return count;
    }
};