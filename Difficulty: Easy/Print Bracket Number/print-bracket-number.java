//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();
            Solution ob = new Solution();
            ArrayList<Integer> result = ob.bracketNumbers(S);
            for (int value : result) out.print(value + " ");
            out.println();
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    ArrayList<Integer> bracketNumbers(String str) {
        // code here
        int n = 1;
        Stack<Integer> stack = new Stack<>();
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        for(int i = 0;i<str.length();i++){
            if(str.charAt(i) == '('){
                ans.add(n);
                stack.add(n);
                n++;
            }
            else if(str.charAt(i) == ')'){
                ans.add(stack.pop());
            }
        }
        return ans;
    }
};