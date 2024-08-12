#User function Template for python3

class Solution:
    def sum_of_middle_elements(self, arr1, arr2):
        # code here
        arr = [None] * (len(arr1) + len(arr2))
        i = 0
        j = 0
        k = 0
        while(i<len(arr1) and j<len(arr2)):
            if(arr1[i]<arr2[j]):
                arr[k] = arr1[i]
                k += 1
                i += 1
            else:
                arr[k] = arr2[j]
                k += 1
                j += 1
                
        while(i<len(arr1)):
            arr[k] = arr1[i]
            k += 1
            i += 1
            
        while(j<len(arr2)):
            arr[k] = arr2[j]
            k += 1
            j += 1
        
        
        leng = len(arr)
        
        if(leng%2 == 0):
            return arr[leng//2] + arr[(leng//2)-1]
        return arr[(leng//2)]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

input = sys.stdin.read


def main():
    input_lines = input().strip().split("\n")
    t = int(input_lines[0])

    index = 1
    results = []
    while t > 0:
        arr = list(map(int, input_lines[index].strip().split()))
        brr = list(map(int, input_lines[index + 1].strip().split()))
        index += 2

        solution = Solution()
        res = solution.sum_of_middle_elements(arr, brr)
        results.append(res)

        t -= 1

    for result in results:
        print(result)


if __name__ == "__main__":
    main()

# } Driver Code Ends