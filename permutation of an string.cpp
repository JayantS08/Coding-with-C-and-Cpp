#include <bits/stdc++.h>
using namespace std;

void swap(char *x,char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a,int i,int n)
{
    if(i==n)
        cout<<a<<endl;
    else
	{
        for(int j = i;j<=n;j++)
		{
	        if(i!=j)
	        	swap((a+i),(a+j));
	        permute(a,i+1,n);
	        if(i!=j)
	        	swap((a+i),(a+j));
        }
    }

}

int main()
{
    char s[10000];
    cin>>s;
    /*
    
	This is also the solution :---
	
	sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }
    while(next_permutation(s.begin(),s.end()));
	
	*/
    int n = strlen(s);
    permute(s,0,n-1);
    return 0;
}
