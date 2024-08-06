#User function Template for python3
class Solution:
    def isValid(self, str):
        #code here
        arr = str.split('.')
        if(len(arr)<4 or len(arr)>4):
            return False
        for s in arr:
            if(s=='' or int(s)<0 or int(s)>255):
                return False
            if(s!='' and len(s)>1 and s[0]=='0'):
                return False
        
        return True        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        ob = Solution()
        if (ob.isValid(s)):
            print("true")
        else:
            print("false")

# } Driver Code Ends