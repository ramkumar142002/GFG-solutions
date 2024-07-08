//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String line = in.readLine();
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

            int key = Integer.parseInt(in.readLine().trim());

            out.println(new Solution().search(arr, key));
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int search(int[] arr, int key) {
        // Complete this function
        int pivot = p(arr);
        // System.out.println(pivot);
        if(pivot == -1) return bin(arr,key,0,arr.length-1);
        if(arr[pivot] == key) return pivot;
        int ans = bin(arr,key,0,pivot-1);
        if(ans==-1) return bin(arr,key,pivot+1,arr.length-1);
        return ans;
    }
    public int p(int[] nums){
        int s = 0,e = nums.length-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(mid < e && nums[mid] > nums[mid+1]) return mid;
            if(mid > s && nums[mid] < nums[mid-1]) return mid-1;
            if(nums[s] >= nums[mid]) e = mid - 1;
            else s = mid+1;
        }
        return -1;
    }
    public int bin(int[] nums,int target,int start,int end){
        int s = start,e = end;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }
}