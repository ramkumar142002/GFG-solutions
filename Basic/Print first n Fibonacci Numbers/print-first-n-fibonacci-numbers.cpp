//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        if(n==1) return {1};
        vector<long long> x;
        
        long long a=1,b=1;
        // cout<<a<<" "<<b<<" ";
        x.push_back(a);
        x.push_back(b);
        long long i=2;
        while(i<n){
            long long c=a+b;
            x.push_back(c);
            b=c;
            a=c-a;
            i++;
        }
        return x;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends