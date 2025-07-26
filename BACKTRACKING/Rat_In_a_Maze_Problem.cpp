class Solution {
  public:
    void dfs(vector<vector<int>> &maze,vector<string> &ans,string &s,vector<vector<int>> &vis,int row,int col)
    {
        int n=maze.size();
        if(row<0 || col<0 || row==n || col==n || maze[row][col]==0 || vis[row][col]==1)
        {
            return;
        }
        
        
        if(row==n-1 && col==n-1)
        {
            ans.push_back(s);
            return;
        }
        
        vis[row][col]=1;
        
        int x[]={1,-1,0,0};
        int y[]={0,0,-1,1};
        char dir[] = {'D', 'U', 'L', 'R'};
        for(int i=0;i<4;i++)
        {
            int nrow=row+x[i];
            int ncol=col+y[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && maze[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                s.push_back(dir[i]);
                dfs(maze, ans, s, vis, nrow, ncol);
                s.pop_back();
            }
        }
        vis[row][col]=0;
        
    }
  
  
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n=maze.size();
        vector<string> ans;
        string s;
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(maze[0][0]==1)
        {
            dfs(maze,ans,s,vis,0,0);
            
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};