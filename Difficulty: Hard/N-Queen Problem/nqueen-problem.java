//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine());

            Solution ob = new Solution();
            ArrayList<ArrayList<Integer>> ans = ob.nQueen(n);
            if (ans.size() == 0)
                System.out.println("-1");
            else {
                for (int i = 0; i < ans.size(); i++) {
                    System.out.print("[");
                    for (int j = 0; j < ans.get(i).size(); j++)
                        System.out.print(ans.get(i).get(j) + " ");
                    System.out.print("] ");
                }
                System.out.println();
            }
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public ArrayList<ArrayList<Integer>> nQueen(int n) {
        // code here
        char[][] board = new char[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                board[i][j] = '.';
            }
        }
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>() ;
        ArrayList<Integer> temp = new ArrayList<>();
        queen(board,ans,0,n,temp);
        // System.out.println(ans);
        return ans;
    }
    public void queen(char[][] board,ArrayList<ArrayList<Integer>> ans,int row,int n,ArrayList<Integer> temp){
        if(row == n){
            ans.add(new ArrayList<>(temp));
            // System.out.println(temp);
            return ;
        }
        for(int col = 0;col<n;col++){
            if(isSafe(board,row,col)){
                board[row][col] = 'Q';
                temp.add(col+1);
                queen(board,ans,row+1,n,temp);
                temp.remove(temp.size()-1);
                board[row][col] = '.';
            }
        }
    }
    public boolean isSafe(char[][] board,int row,int col){
        for(int i = 0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }
        int minLeft = Math.min(row,col);
        for(int i = 1;i<=minLeft;i++){
            if(board[row-i][col-i] == 'Q') return false;
        }
        int minRight = Math.min(row,board.length-col-1);
        for(int i = 1;i<=minRight;i++){
            if(board[row-i][col+i] == 'Q') return false;
        }
        
        return true;
    }
}