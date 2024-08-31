//{ Driver Code Starts
import java.util.*;

public class GFG {
    // Function to check if v2 is a subsequence of v1
    public static boolean isSubSequence(int[] v1, int[] v2) {
        int m = v2.length;
        int n = v1.length;
        int j = 0; // For index of v2

        // Traverse v1 and v2
        for (int i = 0; i < n && j < m; i++) {
            if (v1[i] == v2[j]) {
                j++;
            }
        }
        return j == m;
    }

    // Driver code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String[] input = sc.nextLine().split(" ");
            int[] arr = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
            int n = arr.length;
            Solution obj = new Solution();
            List<Integer> res = obj.find3Numbers(arr);
            if (!res.isEmpty() && res.size() != 3) {
                System.out.println(-1);
            } else {
                int[] resArray = res.stream().mapToInt(Integer::intValue).toArray();
                if (resArray.length == 0) {
                    System.out.println(0);
                } else if (resArray[0] < resArray[1] && resArray[1] < resArray[2] &&
                           isSubSequence(arr, resArray)) {
                    System.out.println(1);
                } else {
                    System.out.println(-1);
                }
            }
        }
        sc.close();
    }
}

// } Driver Code Ends


/*Complete the function below*/

// import java.util.ArrayList;
// import java.util.List;

class Solution {
    // Function to find three numbers such that arr[smaller[i]] < arr[i] < arr[greater[i]]
    public List<Integer> find3Numbers(int[] arr) {
        List<Integer> result = new ArrayList<>();
        boolean found = fun(arr, 0, -1, result);
        return result;
    }

    public boolean fun(int[] arr, int ind, int prev, List<Integer> temp) {
        if (temp.size() == 3) {
            return true;
        }
        if (ind >= arr.length) {
            return false;
        }

        // If current element is greater than the previous one
        if (arr[ind] > prev) {
            temp.add(arr[ind]);
            // If adding this element forms a valid sequence, return true
            if (fun(arr, ind + 1, arr[ind], temp)) {
                return true;
            }
            // Otherwise, backtrack
            temp.remove(temp.size() - 1);
        }

        // Try skipping the current element
        return fun(arr, ind + 1, prev, temp);
    }
}
