//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int arr[][] = new int[n][m];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            new Solution().setMatrixZeroes(arr);
            for (int[] row : arr) {
                for (int val : row) {
                    System.out.print(val + " ");
                }
                System.out.println();
            }

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


//Back-end complete function Template for Java
class Solution {
    public void setMatrixZeroes(int[][] mat) {
        int rows[] = new int[mat.length];
        Arrays.fill(rows,0);
        int cols[] = new int[mat[0].length];
        Arrays.fill(cols,0);
        
        for(int i = 0;i<mat.length;i++){
            for(int j = 0;j<mat[i].length;j++){
                if(mat[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        for(int i = 0;i<rows.length;i++){
            if(rows[i] == 1){
                for(int j = 0;j<mat[i].length;j++){
                    mat[i][j] = 0;
                }
            }
        }
        for(int i = 0;i<cols.length;i++){
            if(cols[i] == 1){
                for(int j = 0;j<mat.length;j++){
                    mat[j][i] = 0;
                }
            }
        }
    }
}