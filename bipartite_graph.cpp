class Solution {
public:
    bool bfs(vector<vector<int>>& graph,int src,int *color)
    {
        if(graph[src].size()==0)
            return true;
        color[src]=1;
        queue<int>q;
        q.push(src);
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            
            for(int i=0;i<graph[u].size();i++)
            {
                
                int v=graph[u][i];
                //cout<<v<<endl;
                if(color[v]==-1)
                {
                    color[v]=1-color[u];
                    q.push(v);
                    
                }
                else
                if(color[v]==color[u]){
                    return false;
                }
                    
                
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        //cout<<n<<endl;
        if(n==0)
            return false;
        if(n==1&&graph[0].size()==0)
            return true;
        int color[n];
        for(int i=0;i<n;i++)
            color[i]=-1;
        int res=true;
        for(int i=0;i<n;i++)
            if(color[i]==-1)
                res=res&&bfs(graph,i,color);
        return res;
        
    }
};
