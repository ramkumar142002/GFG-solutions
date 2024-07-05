//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] S1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(S1[0]);
            int m = Integer.parseInt(S1[1]);
            int[][] image =  new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S2 = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++)
                    image[i][j] = Integer.parseInt(S2[j]);
            }
            String[] S3 = br.readLine().trim().split(" ");
            int sr = Integer.parseInt(S3[0]);
            int sc = Integer.parseInt(S3[1]);
            int newColor = Integer.parseInt(S3[2]);
            Solution obj = new Solution();
            int[][] ans = obj.floodFill(image, sr, sc, newColor);
            for(int i = 0; i < ans.length; i++){
                for(int j = 0; j < ans[i].length; j++)
                    System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends


class Solution
{
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor)
    {
        // Code here 
        int n = image.length;
        int m = image[0].length;
        int[][] img = new int[n][m];
        img = image;
        int curColor = image[sr][sc];
        
        dfs(sr,sc,img,newColor,curColor);
        return img;
    }
    public void dfs(int sr,int sc,int[][] img,int newColor,int curColor){
        img[sr][sc] = newColor;
        
        int n = img.length;
        int m = img[0].length;
        
        int[] delrow=new int[]{-1,0,1,0};
        int[] delcol=new int[]{0,1,0,-1};
        
        for(int i = 0;i<4;i++){
            int newrow = sr+delrow[i];
            int newcol = sc+delcol[i];
            
            if(newrow>-1 && newrow<n && newcol>-1 && newcol<m && 
            img[newrow][newcol]==curColor && img[newrow][newcol]!=newColor){
                img[newrow][newcol] = newColor;
                dfs(newrow,newcol,img,newColor,curColor);
            }
        }
    }
}