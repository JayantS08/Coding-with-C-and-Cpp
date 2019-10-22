#include<iostream>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <string.h>
#include<set>
using namespace std;
char ars[10][100];
int arw[10];
char ars1[100];
int ind=0,ind1=0;

int isSubstring(string s1,string s2)
{
	int m = s1.length();
	int n=s2.length();
	
	for(int i=0;i<=n-m;i++)
	{
		int j;
		for(j=0;j<m;j++)
			if(s2[i+j]!=s1[j])
				break;
		
		if(j==m)
			return i;
	}
	
	return -1;
}



string decimal_binary(int n,int m)
{
 char a[20];
 int c=0; 
  for(int i=0;i<m;i++)
  {
   if(n%2==0)
  	{
		a[c]='0';
  		c++;
  	}
   else 
   	{
  		a[c]='1';
  		c++;
  	}
   n=n/2;
  }
  a[c]='\0';
 string b=a;
 reverse(b.begin(),b.end());
 return b;
}



int alter_bit_in_bit(string a,string b)
{
int len=a.length();
int c=0,d=0,k;
  for(int i=0;i<len;i++)
   {
    	if(a[i]!=b[i])
  		{
  	 		c++;
  	 		k=i;
  		}
      	else if(a[i]==b[i])
      		d++;
   }
if(c==1)
{
 	return k; 
}             
else if(d==len) 
{
	return -2;
}        
else
{
	return -1;                  
} 

}
string alter_bit(string a,int l)    
{ 
 a[l]='_';
 return a;
}


void check_like(string a,vector<string>&b)
{
 int counter=0,len=b.size();
  for(int i=0;i<len;i++)
  {
	    if(alter_bit_in_bit(a,b[i])==-2)
		{
			return;
		}
	    else 
		{
			counter++;
		}
  }
 if(counter==len)
 b.push_back(a);
 return;
}



int main() 
{
 int i2,j2,k2,min,t,i;
 vector<vector<string> >f;                           
 vector<vector<string> >fc;                           
 set<string>final;                                  
 set<string>temp2;                                   
 string s,result;
 vector<vector<int> >mint;                           
 int fn,m; 
 cout<<"Enter the no. of function to be entered : ";
 cin>>fn;
 if(fn<=0){cout<<"oops!! Input can't be 0 or negative. ";return 0;}
 cout<<"Enter the no. of variables for the functions : ";
 cin>>m;
 if(m<=0){cout<<"oops!! Input can't be 0 or negative. ";return 0;}
 
for(i2=0;i2<fn;i2++)
 {
   cout << "\n";
   vector<int>temp;
   int nm;
   cout << "Enter the functions in SOP only \n" << endl;
   cout<<"for Function "<<i2+1<<":\n\n";
   cout<<"Enter the no. of minterms: ";
   cin>>nm;
   if(nm<=0)
   {cout<<"Invalid input ";return 0;}
   
   for(j2=0;j2<nm;j2++)
    {
    	cout<<"Enter the " << j2+1 <<" minterms (0, "<<pow(2,m)-1<<") : ";
      int a;
      cin>>a;
      cout <<"\n";
      if(a<0 || a>pow(2,m))
       { cout<<"Invalid Input.minterm should be between 0 and "<<pow(2,m)-1;return 0;}
      temp.push_back(a);
    }
   mint.push_back(temp);
}
for(i2=0;i2<fn;i2++)
{
   int d=0;
   vector<int>temp;
	for(j2=0;j2<pow(2,m);j2++)
	{
	  if(mint[i2][d]!=j2)
		temp.push_back(j2);
	  else
	        d++;
	}
   mint.push_back(temp);
}
for(int i1=0;i1<(2*fn);i1++)
{
    int i,j,k,n,l,row,col,count;
    n=mint[i1].size();
    vector<string>temps;
    vector<string>terms;
    vector<string>vect;
    vector<string>prime;
    vector<string>temp1;
    vector<string>ep;
    vector<int>temp2;
    vector<pair<int,int> >temp3;
    int *a=new int[n];
    for(int j=0;j<n;j++)
	a[j]=mint[i1][j];
    for(int i=0;i<n;i++)
	vect.push_back(decimal_binary(a[i],m));
    for(int i=0;i<vect.size();i++)
	 terms.push_back(vect[i]);
         
    while(!vect.empty())
      {
        for(i=0;i<vect.size()-1;i++)
	{
	  int c=0;
          for(j=i+1;j<vect.size();j++)
	  {
	     l=alter_bit_in_bit(vect[i],vect[j]);
	     if(l!=-1 && l!=-2)
	      {
	        temp1.push_back(alter_bit(vect[i],l));
	        temp2.push_back(j);
	      }
             else c++;
          }
          if(c==j-i-1)
           { int d=0;
             for(int k=0;k<temp2.size();k++)
		{
		    if(i==(temp2[k]))
		     	{d=1;break;}
		}
	     if(d==0) check_like(vect[i],prime);
	   }
         }
         int d=0;
         for(int k=0;k<temp2.size();k++)
		  {
		  	if(i==(temp2[k]))
		  		{d=1;break;}
		  }
         if(d==0)check_like(vect[i],prime);
	 vect.clear();
	 for(int i=0;i<temp1.size();i++)
	   {
	      vect.push_back(temp1[i]);
           }
		   temp1.clear();
		   temp2.clear();
       }
      
	vector<string>().swap(temp1);   
	vector<int>().swap(temp2);      
	vector<string>().swap(vect);    
	row=prime.size();                
	col=n;                          
	int**t = new int*[row+1];       
	for(int i=0;i<row+1;i++)
	{  t[i]=new int[col];
	}

	for(int i=0;i<row+1;i++)        
	{for(int j=0;j<col;j++)
	  t[i][j]=0;
	}
       
	for(int i=0;i<row;i++)
	{int c;
	 int n1=terms.size();
	 int m1=prime[i].length();
	 for(int j=0;j<n1;j++)
	 { c=1;
	   for(int k=0;k<m1;k++)
	   { if(prime[i][k]!='_'){if(prime[i][k]!=terms[j][k]){c=0;break;}}}
	   if(c==1)t[i][j]=1;
	 }
	 }
        
	for(j=0;j<col;j++)
	 {count=0;
	   for(i=0;i<row;i++)
	    { if(t[i][j]==1) {count++;k=i;}}
	   if(count==1){temp3.push_back(make_pair(j,k));}
	 }
       
	for(i=0;i<temp3.size();i++)
	{ if(t[row][temp3[i].first]!=1) 
	   { ep.push_back(prime[temp3[i].second]);
	     t[temp3[i].second][temp3[i].first]=-1;
	     t[row][temp3[i].first]=1;
	     for(j=0;j<col;j++)
		{ if(t[temp3[i].second][j]==1)
		    {for(k=0;k<row;k++)
		      { if(t[k][j]==1)
		         t[k][j]=-1;
		      }
		     t[row][j]=1;       
		    }
		 }
	     }
	}
	temp3.clear();
	for(i=0;i<row;i++)
	{ count=0;
	  for(j=0;j<col;j++)
	  { if(t[i][j]==1)
	    count++;
	  }
	  if(count>0){temp3.push_back(make_pair(count,i));}
	}
	sort(temp3.begin(),temp3.end());
      if(!temp3.empty())
	{i=temp3.size()-1;
		{ ep.push_back(prime[temp3[i].second]);
		  for(j=0;j<col;j++)
		    { if(t[temp3[i].second][j]==1)
			{ for(k=0;k<row;k++)
			  { if(t[k][j]==1)
			     {t[k][j]=-1;}
			  }
			}
		    }
		}

		while(1)
		{ k=1;
		   for(i=0;(i<temp3.size()-k && i>=0);i++)
		   {count=0;
		   for(j=0;j<col;j++)
		      { if(t[temp3[i].second][j]==1)
			count++;
		      }
		   if(count>0)
		    {temp3[i].first=count;}else temp3[i].first=0;}
		   sort(temp3.begin(),temp3.end()-k);
		   i=temp3.size()-1-k;
		   if(temp3[i].first>0)
		   {ep.push_back(prime[temp3[i].second]);
		     for(j=0;j<col;j++)
		      { if(t[temp3[i].second][j]==1)
			 { for(k=0;k<row;k++)
			    { if(t[k][j]==1)
			     {t[k][j]=-1;}
			    }
			 }
		      }
		   }  
		  else 
		  break;
		k++;
		}
		for(int i=0;i<ep.size();i++)
		{ temps.push_back(ep[i]); }
         }
	else
	{
	    for(int i=0;i<prime.size();i++)
	     {
	        temps.push_back(prime[i]);
	     }
	}
if(i1<fn)
f.push_back(temps);                      
else
fc.push_back(temps);                     
}
cout <<"\n\n";
cout<<"The functions are: \n \n";
for(int j=0;j<f.size();j++)
{ cout<<"F"<<j+1<<"= ";
  for(int k=0;k<f[j].size();k++)
  { 
    for(int l=0;l<f[j][k].size();l++)
    { if(f[j][k][l]=='0')
	{
		cout<<char(l+65)<<"'";
		ars[ind][ind1]=char(l+65);
		ind1++;
		ars[ind][ind1]=char(39);
		ind1++;
	}
      else if(f[j][k][l]=='1')
	{
	  	cout<<char(l+65);
	  	ars[ind][ind1]=char(l+65);
		ind1++;
	}
  } 
 if(k!=f[j].size()-1)
 {
 	cout<<'+';
 	ars[ind][ind1]=char(43);
	ind1++;
 }
}
  cout<<endl;
  ars[ind][ind1]='\0';
  ind++;
  ind1=0;
}
for(int j=0;j<fc.size();j++)
{ cout<<"F"<<j+1<<"'= ";
  for(int k=0;k<fc[j].size();k++)
  {  
    for(int l=0;l<fc[j][k].size();l++)
    { if(fc[j][k][l]=='0')
	{
		cout<<char(l+65)<<"'";
		ars[ind][ind1]=char(l+65);
		ind1++;
		ars[ind][ind1]=char(39);
		ind1++;
	}
      else if(fc[j][k][l]=='1')
	{
	  	cout<<char(l+65);
	  	ars[ind][ind1]=char(l+65);
		ind1++;
	}
	  
  } 
  if(k!=fc[j].size()-1)
  	{
  		cout<<'+';
		ars[ind][ind1]=char(43);
		ind1++;
	}
}cout<<endl;
	ars[ind][ind1]='\0';
	ind++;
	ind1=0;
	}
t=pow(2,fn);                              
 i=0;
  s=decimal_binary(i,fn);                  
   for(int j=0;j<fn;j++)                            
   {if(s[j]=='0'){for(int k=0;k<fc[j].size();k++)
                 final.insert(fc[j][k]);                    
                }
    else{for(int k=0;k<f[j].size();k++)
                 final.insert(f[j][k]);
                }
   }
   min=final.size();
   result=s;                             
   for(int i=1;i<t;i++)                     
   {temp2.clear();  
    s=decimal_binary(i,fn);
   for(int j=0;j<fn;j++)
    {if(s[j]=='0'){for(int k=0;k<fc[j].size();k++)
                 temp2.insert(fc[j][k]);
                }
    else{for(int k=0;k<f[j].size();k++)
                 temp2.insert(f[j][k]);
                }
     
    }
    
    
    if(min>temp2.size())
    {min=temp2.size();
     final.clear();
     final.insert(temp2.begin(), temp2.end());
     result=s;
     temp2.clear();
    }
   }
cout<<"\nThe functions selected for pla are: ";
   for(i=0;i<fn;i++)
   { if(result[i]=='0')
   	{
   		cout<<"F"<<i+1<<"'";
   		arw[ind1]=i+fn;
   		ind1++;
	}           
     else 
	{
		cout<<"F"<<i+1;
		arw[ind1]=i;
   		ind1++;
 	}
	 cout<<" ";
   }
   arw[ind1]='\0';
   cout <<"\n\n\n";
   cout << "Function " << "\t" << "S.no." << "\t" << "Inputs" << "\t\t" << "Outputs" <<endl;
   cout << "\t\t\t";
   for (int l=0;l<m;l++)
   {
   	cout << char(65+l) << "  ";
   }
   cout << "\t" ;
   for (int l=0;l<fn;l++)
   {
   	cout << "F"<<l+1<< "  ";
   }
   cout << "\n";
   ind1=0;
   int counter=0;
   int c=0;
   int pterm=1;
   char str1[10],str[10];
   
   int lp=fn-1;
   while(lp--)
   	{
   	ind=arw[counter];
   	int ind2=arw[counter+1];
	counter++;
   	int check=0;
   	for(int l=0;ars[ind][l]!='\0';l++)
   	{
   		//cout << ars[ind] << endl;
   		if(ars[ind][l]=='+')
   		{
   			check=0;
   			str1[c]='\0';
   			if(isSubstring(str1,ars[ind2])==-1)
				{
					cout << str1 <<"\t\t" << pterm <<"\t";
					pterm++;
					for(int re=0;re<m;re++)
					{
						char test[2];
						 test[0] = char(65+re);
						 test[1]='\0';
						int res=isSubstring(test,str1);
						if(res==-1)
							cout << "-" << "  ";
						else if(str1[res+1]==char(39))
							cout << 0 <<"  ";
						else
							cout << 1 << "  ";
					}
					cout << "\t" << "1" << "  " << "-";
				}
			//cout << "\t" << "1" << "  " << "-";
   			strcpy(str1,"");
			c=0;	
			cout <<"\n";
		}
		else
		{
			str1[c]=ars[ind][l];
			c++;	
		}
	}
			check=0;
   			str1[c]='\0';
   			if(isSubstring(str1,ars[ind2])==-1)
				{
					cout << str1 <<"\t\t" << pterm <<"\t";
					pterm++;
					for(int re=0;re<m;re++)
					{
						char test[2];
						 test[0] = char(65+re);
						 test[1]='\0';
						int res=isSubstring(test,str1);
						if(res==-1)
							cout << "-" << "  ";
						else if(str1[res+1]==char(39))
							cout << 0 <<"  ";
						else
							cout << 1 << "  ";
					}
				cout << "\t" << "1" << "  " << "-";
				cout <<"\n";
				}
			
   			strcpy(str1,"");
			c=0;	
			
	}
	
	ind=arw[counter];
	int ind2=arw[counter-1];
	counter++;
   	int check=0;
   	for(int l=0;ars[ind][l]!='\0';l++)
   	{
   		if(ars[ind][l]=='+')
   		{
   			check=0;
   			str1[c]='\0';
   			
					cout << str1 <<"\t\t" << pterm <<"\t";
					pterm++;
					for(int re=0;re<m;re++)
					{
						char test[2];
						 test[0] = char(65+re);
						 test[1]='\0';
						int res=isSubstring(test,str1);
						if(res==-1)
							cout << "-" << "  ";
						else if(str1[res+1]==char(39))
							cout << 0 <<"  ";
						else
							cout << 1 << "  ";
					}
			if(isSubstring(str1,ars[ind2])==-1)
			{
				cout << "\t" << "-" << "  " << "1";
			}
			else
			{
				cout << "\t" << "1" << "  " << "1";
			}
				
   			strcpy(str1,"");
			c=0;	
			cout <<"\n";	
		}
		else
		{
			str1[c]=ars[ind][l];
			c++;	
		}
	}
			check=0;
   			str1[c]='\0';
					cout << str1 <<"\t\t" << pterm <<"\t";
					pterm++;
					for(int re=0;re<m;re++)
					{
						char test[2];
						 test[0] = char(65+re);
						 test[1]='\0';
						int res=isSubstring(test,str1);
						if(res==-1)
							cout << "-" << "  ";
						else if(str1[res+1]==char(39))
							cout << 0 <<"  ";
						else
							cout << 1 << "  ";
					}
			if(isSubstring(str1,ars[ind2])==-1)
			{
				cout << "\t" << "-" << "  " << "1";
			}
			else
			{
				cout << "\t" << "1" << "  " << "1";
			}
   			strcpy(str1,"");
			c=0;	
			cout <<"\n";
   
   
 return 0;
}

