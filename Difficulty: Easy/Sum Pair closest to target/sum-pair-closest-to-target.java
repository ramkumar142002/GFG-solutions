//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            ArrayList<Integer> array = new ArrayList<>();

            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int target = Integer.parseInt(br.readLine());

            Solution ob = new Solution();
            List<Integer> res = ob.sumClosest(arr, target);
            if (res.isEmpty()) {
                System.out.print("[]");
            } else {
                for (Integer num : res) {
                    System.out.print(num + " ");
                }
            }
            System.out.println();
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public List<Integer> sumClosest(int[] arr, int target) {
        // code here
        if(arr.length < 2){
            return Collections.emptyList();
        }
        Arrays.sort(arr);
        Integer[] ans = new Integer[2];
        int minDiff = Integer.MAX_VALUE;
        int i = 0, j =arr.length-1;
        while(i<j){
            int sum = arr[i] + arr[j];
            if(sum == target){
                ans[0] = arr[i];
                ans[1] = arr[j];
                return Arrays.asList(ans);
            }
            
            int mini = Math.abs(target - (arr[j]+arr[i]));
            if(mini < minDiff){
                minDiff = mini;
                ans[0] = arr[i];
                ans[1] = arr[j];
            }
            
            if(sum>target){
                j--;
            }else{
                i++;
            }
        }
        return Arrays.asList(ans);
    }
}