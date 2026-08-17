#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(vector<vector<int>>& image, int sr, int sc, int color, int prevCol){
    int m = image.size(); //row
    int n = image[0].size(); //col

    if(sr<0 || sc<0 || sr>=m || sc>=n || image[sr][sc] != prevCol) return;

    image[sr][sc] = color;
    
    dfs(image, sr+1 ,sc, color, prevCol);
    dfs(image, sr-1 ,sc, color, prevCol);
    dfs(image, sr ,sc+1 , color, prevCol);
    dfs(image, sr ,sc-1, color, prevCol);

}

 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int prevCol = image[sr][sc];
      if(prevCol == color) return image;
    dfs(image, sr, sc, color, prevCol);
    return image;        
 }

 //by bfs
 void bfs(vector<vector<int>>& image, int sr, int sc, int color, int prevCol){
    int m = image.size();
    int n = image[0].size();

    queue<pair<int,int>> q;
    q.push({sr,sc});
    image[sr][sc] = color;

    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};

    while(!q.empty()){
       auto node = q.front();
       q.pop();
       int row = node.first;
       int col = node.second;
      for(int k = 0; k < 4; k++){
            int nRow = row + dRow[k];
            int nCol = col + dCol[k];

            if(nRow>=0 && nRow <m && nCol >=0 && nCol <n &&  image[nRow][nCol] == prevCol){
                q.push({nRow, nCol});
                image[nRow][nCol] = color;
            }
        }

       }

    }
 
  vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int color) {
    int prevCol = image[sr][sc];
    if(prevCol == color) return image;;
    bfs(image, sr, sc, color, prevCol);
    return image;        
    }