class Solution {
public:
    int bfs(vector<vector<int>> &grid,vector<vector<int>> &vis, queue<pair<pair<int,int>,int>> &q)
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            ans=max(ans,time);
            q.pop();

            int x[]={1,-1,0,0};
            int y[]={0,0,-1,1};

            for(int i=0;i<4;i++)
            {
                int nrow=row+x[i];
                int ncol=col+y[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                {
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }



    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                }

            }
        }


        return bfs(grid,vis,q);

        
    }
};