//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int V = Integer.parseInt(read.readLine());
            
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            
            for(int i=0; i<V; i++)
            {
                String S[] = read.readLine().split(" ");
                ArrayList<Integer> temp = new ArrayList<>();
                for(int j=0; j<V; j++)
                    temp.add(Integer.parseInt(S[j]));
                adj.add(temp);
            }

            Solution ob = new Solution();
            System.out.println(ob.numProvinces(adj,V));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int numProvinces(ArrayList<ArrayList<Integer>> adjMat, int V) {
        // code here
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        for(int i = 0;i<V;i++){
            adj.add(new ArrayList<Integer>());
        }
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(adjMat.get(i).get(j)==1 && i!=j){
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }
        boolean[] visited = new boolean[V];
        int count = 0;
        for(int i = 0;i<V;i++){
            if(visited[i]==false){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
    static void dfs(Integer node,ArrayList<ArrayList<Integer>> adj,boolean[] vis){
        vis[node] = true;
        
        for(Integer it : adj.get(node)){
            if(vis[it]==false){
                dfs(it,adj,vis);
            }
        }
    }
};