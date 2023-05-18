#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int delr[],int delc[],int r,int c)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&grid[nr][nc])
            {
                dfs(grid,vis,delr,delc,nr,nc);
            }
            
        }
        
    }
    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delr[]={1,-1,0,0};
        int delc[]={0,0,-1,1};
        if(n==1||m==1)
        return 0;
        
        for(int i=0;i<n;i++)
        {
            int j=0;
            if(!vis[i][j]&&grid[i][j])
            dfs(grid,vis,delr,delc,i,j);
            
            j=m-1;
            if(!vis[i][j]&&grid[i][j])
            dfs(grid,vis,delr,delc,i,j);
        }
         for(int j=0;j<m;j++)
        {
            int i=0;
            if(!vis[i][j]&&grid[i][j])
            dfs(grid,vis,delr,delc,i,j);
            
            i=n-1;
            if(!vis[i][j]&&grid[i][j])
            dfs(grid,vis,delr,delc,i,j);
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               
                if(!vis[i][j]&&grid[i][j]==1)
                {
                     count++;
            dfs(grid,vis,delr,delc,i,j);
                }
            }
        }
        
        return count;
        
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> matrix(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution obj;
        int ans=obj.closedIslands(matrix,n,m);
        cout<<ans<<endl;
    }
    return 0;
}