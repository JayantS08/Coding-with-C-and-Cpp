#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
		node(int d)
		{
			data = d;
			left = NULL;
			right= NULL;
		}
};
class sol
{
	public : 
		node * insert (node *root,char data)
		{
			if(root== NULL)
			{
				return new node(data);
			}
			else
			{
				node *cur;
				if(height((root->left))<=height((root->right)))
				{
					cur=insert(root->left,data);
					root->left=cur;
				}
				else
				{
					cur=insert(root->right,data);
					root->right=cur;
				}
			}
			return root;	
		}
		
		
		int height(node* root) 
		{ 
		    if (root == NULL) 
		        return 0; 
		    return 1 + min(height(root->left), height(root->right)); 
		}
};

void printPostorder(node* root) 
{ 
    if (root == NULL) 
        return; 

    stack<node *> s1, s2; 

    s1.push(root); 
    node* Node; 

    while (!s1.empty()) 
	{ 
        Node = s1.top(); 
        s1.pop(); 
        s2.push(Node); 
        if (Node->left) 
            s1.push(Node->left); 
        if (Node->right) 
            s1.push(Node->right); 
    } 
    while (!s2.empty()) 
	{ 
        Node = s2.top(); 
        s2.pop(); 
        cout << Node->data << " "; 
    } 
} 
  
int main()
{
	int t;
	int data;
	sol myTree;
	cout<<"Enter the number of inputs : ";
	cin>>t;
	node *root=NULL;
	int arr[t];
	int i=0;
	while(t--)
	{
		cout<<"enter number : ";
		cin>>data;
		cout<<"\n";
		root=myTree.insert(root,data);
	}
	printPostorder(root);
	return 0;
}
