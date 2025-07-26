class Solution {
public:
    void bfs(int i,int j,vector<vector<char>> &vis, vector<vector<char>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]='1';
        queue<pair<int,int>> q;
         q.push({i,j});
        while (!q.empty()) {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int x[]={1,-1,0,0};
            int y[]={0,0,-1,1};

            for(int i=0;i<4;i++)
            {
                int nrow=row+x[i];
                int ncol=col+y[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]=='0')
                {
                    vis[nrow][ncol]='1';
                    q.push({nrow,ncol});
                }

            }

                        
         }
    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<char>> vis(m, vector<char>(n, '0'));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] != '1') {
                    ans++;
                    bfs(i,j,vis,grid);
                   
                    }
                }
        }

        return ans;
    }
};