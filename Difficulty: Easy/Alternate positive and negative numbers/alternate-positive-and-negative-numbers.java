//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String input = br.readLine();
            String[] inputArray = input.split("\\s+");
            ArrayList<Integer> arr = new ArrayList<>();

            for (String s : inputArray) {
                arr.add(Integer.parseInt(s));
            }

            new Solution().rearrange(arr);
            for (int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    void rearrange(ArrayList<Integer> arr) {
        // code here
        ArrayList<Integer> p = new ArrayList<>();
        ArrayList<Integer> n = new ArrayList<>();
        ArrayList<Integer> a = new ArrayList<>();
        
        for(int i = 0;i<arr.size();i++){
            if(arr.get(i)>-1){
                p.add(arr.get(i));
            }
            else n.add(arr.get(i));
        }
        // Collections.sort(p,Collections.reverseOrder());
        // Collections.sort(n);
        int i = 0,j = 0;
        while(i<p.size() && j<n.size()){
            a.add(p.get(i));
            a.add(n.get(j));
            i++;j++;
        }
        while(i<p.size()){
            a.add(p.get(i));
            i++;
        }
        while(j<n.size()){
            a.add(n.get(j));
            j++;
        }
        for (int k = 0; k < arr.size(); k++) {
            arr.set(k, a.get(k));
        }
    }
}