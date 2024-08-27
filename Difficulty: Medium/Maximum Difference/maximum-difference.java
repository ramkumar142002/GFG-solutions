//{ Driver Code Starts
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String input = br.readLine();
            String[] inputs = input.split(" ");
            int[] arr = new int[inputs.length];

            for (int i = 0; i < inputs.length; i++) {
                arr[i] = Integer.parseInt(inputs[i]);
            }

            Solution ob = new Solution();
            System.out.println(ob.findMaxDiff(arr));
        }
    }
}

// } Driver Code Ends


class Solution {
    public int findMaxDiff(int[] arr) {
        // code here
        int[] left=new int[arr.length];
        int[] right=new int[arr.length];
        for(int i=0;i<arr.length;i++){
            int min=0;
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    min=arr[j];
                    break;
                }
            }
            left[i]=min;
        }
        for(int i=0;i<arr.length;i++){
            int min=0;
            for(int j=i+1;j<arr.length;j++){
                if(arr[j]<arr[i]){
                    min=arr[j];
                    break;
                }
            }
            right[i]=min;
        }
        int ans=0;
        for(int i=0;i<arr.length;i++){
            ans=Math.max(ans,Math.abs(left[i]-right[i]));
        }
        return ans;
    }
}
