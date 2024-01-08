//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node* ans = new Node();
        ans->data = NULL;
        Node* temp = ans;
        while(node1!=NULL && node2!=NULL){
            if(node1->data<node2->data){
                Node *t = new Node();
                t->data = node1->data;
                ans->next = t;
                node1 = node1->next;
                ans = ans->next;
            }
            else{
                Node *t = new Node();
                t->data = node2->data;
                ans->next = t;
                node2 = node2->next;
                ans = ans->next;
            }
        }
        while(node1!=NULL){
            Node *t = new Node();
            t->data = node1->data;
            ans->next = t;
            node1 = node1->next;
            ans = ans->next;
        }
        while(node2!=NULL){
            Node *t = new Node();
            t->data = node2->data;
            ans->next = t;
            node2 = node2->next;
            ans = ans->next;
        }
        Node* d = temp;
        temp = temp->next;
        ans = temp;
        // delete d;
        
        d = NULL;
        while(temp!=NULL){
            Node* next = temp->next;
            temp->next = d;
            d = temp;
            temp = next;
        }
        return d;
        
        // return d;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends