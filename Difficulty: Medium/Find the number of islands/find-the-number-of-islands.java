//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                String[] S = br.readLine().trim().split(" ");
                for (int j = 0; j < m; j++) {
                    grid[i][j] = S[j].charAt(0);
                }
            }
            Solution obj = new Solution();
            int ans = obj.numIslands(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Pair{
    int first;
    int second;
    public Pair(int f,int s){
        this.first = f;
        this.second = s;
    }
}
class Solution {
    // Function to find the number of islands.
    public int numIslands(char[][] grid) {
        // Code here
        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];
        int count = 0;
        
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(grid[row][col] == '1' && vis[row][col] == 0){
                    count++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return count;
    }
    
    public void bfs(int row,int col,char[][] grid,int[][] vis){
        vis[row][col] = 1;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(row,col));
        int n = grid.length;
        int m = grid[0].length;
        
        while(!q.isEmpty()){
            int r = q.peek().first;
            int c = q.peek().second;
            q.remove();
            
            for(int drow = -1;drow<2;drow++){
                for(int dcol = -1;dcol<2;dcol++){
                    int nrow = r + drow;
                    int ncol = c + dcol;
                    if(nrow>-1 && nrow<n && ncol>-1 && ncol<m
                    && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol] = 1;
                        q.add(new Pair(nrow,ncol));
                    }
                }
            }
        }
    }
}