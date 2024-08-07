#User function Template for python3

class Solution:
    def kthElement(self, k, arr1, arr2):
        ans = 0
        i,j = (0,0)
        
        while(i<len(arr1) and j<len(arr2)):
            if(arr1[i]<arr2[j]):
                ans = arr1[i]
                i += 1
                k -= 1
            else:
                ans = arr2[j]
                j += 1
                k -= 1
            if(k==0):
                return ans
                
        
        while(i<len(arr1)):
            ans = arr1[i]
            i += 1
            k -= 1
            if(k==0):
                return ans
            
        while(j<len(arr2)):
            ans = arr2[j]
            j += 1
            k -= 1
            if(k==0):
                return ans
            
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while (T > 0):

        k = int(input())
        a = [int(x) for x in input().strip().split()]
        b = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.kthElement(k, a, b))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends