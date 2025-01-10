//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.HashMap;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            ArrayList<Integer> array = new ArrayList<>();

            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int k = Integer.parseInt(br.readLine());

            ArrayList<Integer> ans = new Solution().countDistinct(arr, k);

            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();

            t--;
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        // code here
        HashMap<Integer,Integer> hs = new HashMap<>();
        ArrayList<Integer> a = new ArrayList<>();
        int ans = 0;
        for(int i = 0;i<k;i++){
            hs.put(arr[i], hs.getOrDefault(arr[i],0) + 1);
        }
        
        a.add(hs.size());
        int lastInd = 0;
        int i = k;
        // System.out.println(hs);
        while(i<arr.length){
            if(hs.get(arr[lastInd]) == 1){
                hs.remove(arr[lastInd]);
            }else{
                hs.put(arr[lastInd], hs.get(arr[lastInd])-1);
            }
            hs.put(arr[i], hs.getOrDefault(arr[i],0)+1);
            // System.out.println(hs);
            lastInd++;
            i++;
            a.add(hs.size());
        }
        return a;
    }
}
