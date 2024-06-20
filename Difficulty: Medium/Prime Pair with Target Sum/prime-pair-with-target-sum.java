//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.ArrayList;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            Solution obj = new Solution();
            ArrayList<Integer> res = obj.getPrimes(n);

            IntArray.print(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static ArrayList<Integer> getPrimes(int n) {
        // code here
        if(n<4){
            return new ArrayList<>(Arrays.asList(-1, -1));
        }
        for(int i = 2;i<=n/2;i++){
            if(isPrime(i)==true && isPrime(n-i)==true){
                return new ArrayList<>(Arrays.asList(i, n-i));
            }
        }
        return new ArrayList<>(Arrays.asList(-1, -1));
    }
    public static boolean isPrime(int n){
        for(int i = 2;i<=Math.sqrt(n);i++){
            if(n%i == 0) return false;
        }
        return true;
    }
}
