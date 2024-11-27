vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int prevColor= image[sr][sc];
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int>top = q.front();
                q.pop();
                int x =top.first;
                int y = top.second;
                
                vis[x][y] = true;
                image[x][y] = newColor;
                if(x-1>=0&&!vis[x-1][y]&&image[x-1][y] == prevColor){
                    q.push({x-1,y});
                }
                if(y-1>=0&&!vis[x][y-1]&&image[x][y-1] == prevColor){
                    q.push({x,y-1});
                }
                if(x+1<m&&!vis[x+1][y]&&image[x+1][y] == prevColor){
                    q.push({x+1,y});
                }
                if(y+1<n&&!vis[x][y+1]&&image[x][y+1] == prevColor){
                    q.push({x,y+1});
                }
            }
        }
        return image;
    }
