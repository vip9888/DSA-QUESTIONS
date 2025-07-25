/*https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1*/

class Solution {
  public:
    bool detect(int src,vector<vector<int>> &edges,vector<int> &vis)
    {
        
        queue<pair<int,int>> q;
        
        q.push({src,-1});
        vis[src]=1;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto i:edges[node])
            {
                /* Just check if the node is visited or not, if it is visited then the cycle is present but make sure it is not the aprent node becuase it will be marked visited*/
                if(!vis[i])
                {
                    vis[i]=1;
                    q.push({i,node});
                }
                /* To make sure we are not confusing parent visited with the cycle we are checking with this concition*/
                else if(parent!=i)
                {
                    return true;
                    
                }
                
            }
        }
        
        return false;
        
    }
     
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        
        vector<int> vis(V+1,0);
        vector<vector<int>> adj(V+1);
        
        /*Converting edges array into adjacency list*/
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        /* this is the loop we are running so that if there are multiple components we can run through each component and whenever we have the component with cycle we wil return true */
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis))
                {
                    return true;
                }
            }
            
        }
        
        return false;
        
        
        
        
    }
};

