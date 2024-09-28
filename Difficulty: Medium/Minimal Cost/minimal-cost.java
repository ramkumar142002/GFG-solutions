//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int minimizeCost(int K, int arr[]) {
        // code here
        int N = arr.length;
        int[] dp = new int[N];
        Arrays.fill(dp,0);
        
        dp[0] = 0;
        for(int ind=1;ind<N;ind++){
            int total = Integer.MAX_VALUE;
            for(int j = 1;j<=K;j++){
                if(ind-j>-1){
                    int cost = Math.abs(arr[ind]-arr[ind-j]) + dp[ind-j];
                    total = Math.min(total,cost);
                }
            }
            dp[ind] = total;
        }
        return dp[N-1];
    }
}


//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            int res = obj.minimizeCost(k, arr);

            System.out.println(res);
        }
    }
}
// } Driver Code Ends