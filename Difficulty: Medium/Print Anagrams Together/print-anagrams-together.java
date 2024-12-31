//{ Driver Code Starts
import java.util.*;


// } Driver Code Ends
class Solution {
    public ArrayList<ArrayList<String>> anagrams(String[] arr) {
        // code here
        ArrayList<ArrayList<String>> ans = new ArrayList<>();
        Boolean[] flag = new Boolean[arr.length];
        String[] sorted  =new String[arr.length];
        for (int i = 0; i < arr.length; i++) {
            flag[i] = false; 
            char[] chars = arr[i].toCharArray(); 
            Arrays.sort(chars); 
            sorted[i] = new String(chars); 
        }
        for(int i = 0;i<arr.length;i++){
            if(flag[i] == false){
                ArrayList<String> temp = new ArrayList<>();
                temp.add(arr[i]);
                flag[i] = true;
                for(int j = i+1;j<arr.length;j++){
                    if (sorted[j].equals(sorted[i]) && flag[j] == false){
                        flag[j] = true;
                        temp.add(arr[j]);
                    }
                }
                ans.add(temp);
            }
        }
        return ans;
    }
}


//{ Driver Code Starts.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Ignore the newline after the test case input
        while (t-- > 0) {
            String inputLine = sc.nextLine();
            String[] arr = inputLine.split(" ");

            Solution ob = new Solution();
            ArrayList<ArrayList<String>> result = ob.anagrams(arr);
            result.sort(Comparator.comparing(a -> a.get(0)));
            for (ArrayList<String> group : result) {
                for (String word : group) {
                    System.out.print(word + " ");
                }
                System.out.println();
            }
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends