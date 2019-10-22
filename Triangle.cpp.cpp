#include<iostream>
#include<math.h>
using namespace std;

class point
{
	public:
		int x;
		int y;
	public:
		int a;
		int b;
		point ()
		{
			a=x;
			b=y;
		}
		
};
int trianglecheck(int x,int y,int a, int b,int p,int q);
void drawline(int x,int y,int a,int b,int g,char ar[][150]);
int main()
{
	struct point p1,p2,p3;
	int n; 
	while(1)
	{
		cout << ("Choose \n 1. If you want to place a point \n 2. If you want to draw a line. \n 3. If you want to draw a triangle \n 0. If you want to exit. ") << endl;
		cin >> n;
		if(n==0)
		{
			break;
		}
		else if(n==1)
		{
			int g;
			cout << "Enter size of the grapgh (n*n) : " << endl;
			cin >> g;
			point p1;
			cout << "Enter x- co-ordinate of the point : " << endl;
			cin >> p1.x;
			cout << "Enter y- co-ordinate of the point : " << endl;
			cin >> p1.y; 
			char ar[g][g];
			for (int i=0;i<g;i++)
			{
				for (int j=0;j<g;j++)
				{
					ar[i][j]='.';	
				}
			}
			ar[p1.x+1][p1.y+1]='*';
			for (int i=g-1;i>=0;i--)
			{
				for (int j=0;j<g;j++)
				{
					cout << ar[i][j];	
				}
				cout << "\n";
			}
		}
		else if(n==2)
		{
			int g;
			cout << "Enter size of the grapgh (n*n) : " << endl;
			cin >> g;
			point p1,p2;
			cout << "Enter x- co-ordinate of the 1 point  : " << endl;
			cin >> p1.x;
			cout << "Enter y- co-ordinate of the 1 point : " << endl;
			cin >> p1.y;
			cout << "Enter x- co-ordinate of the 2 point : " << endl;
			cin >> p2.x;
			cout << "Enter y- co-ordinate of the 2 point : " << endl;
			cin >> p2.y; 
			char ar[g][150];
			for (int i=0;i<g;i++)
			{
				for (int j=0;j<g;j++)
				{
					ar[i][j]='.';	
				}
			}
			drawline(p1.x,p1.y,p2.x,p2.y,g,ar);	
			for (int i=g-1;i>=0;i--)
			{
				for (int j=0;j<g;j++)
				{
					cout << " ";
					cout << ar[i][j];
					cout << " ";
				
				}
				cout << "\n";
			}
		}
		else if (n==3)
		{
			
			int g;
			cout << "Enter size of the grapgh (n*n) : " << endl;
			cin >> g;
			point p1,p2,p3;
			cout << "Enter x- co-ordinate of the 1 point  : " << endl;
			cin >> p1.x;
			cout << "Enter y- co-ordinate of the 1 point : " << endl;
			cin >> p1.y;
			cout << "Enter x- co-ordinate of the 2 point : " << endl;
			cin >> p2.x;
			cout << "Enter y- co-ordinate of the 2 point : " << endl;
			cin >> p2.y;
			cout << "Enter x- co-ordinate of the 3 point : " << endl;
			cin >> p3.x;
			cout << "Enter y- co-ordinate of the 3 point : " << endl;
			cin >> p3.y; 
			if(trianglecheck(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y))
			{
			char ar[g][150];
			for (int i=0;i<g;i++)
			{
				for (int j=0;j<g;j++)
				{
					ar[i][j]='.';	
				}
			}
			drawline(p1.x,p1.y,p2.x,p2.y,g,ar);
			drawline(p2.x,p2.y,p3.x,p3.y,g,ar);
			drawline(p3.x,p3.y,p1.x,p1.y,g,ar);
			for (int i=g-1;i>=0;i--)
			{
				for (int j=0;j<g;j++)
				{
					cout << " ";
					cout << ar[i][j];
					cout << " ";	
				}
				cout << "\n";
			}
		}
	}
	}
}
void drawline(int x,int y,int a,int b,int g,char ar[][150])
{
			float m;
			int m1=(b-y);
			int m2=(a-x);
			if(m2==0)
			{
				m=0.000001;
			}
			else
			{
			m=(float)(m1/m2);
		    }
			int h1=(b>y)?b:y;
			int w1=(a>x)?a:x;
			float o;
			float o1;
			int i,j;
			for(i=g-1;i>=0;i--)
			{
				float x1=(float)(i);
				float x2=(float)(y);
				float x3=(float)(m1);
				float x4=(float)(m2);
				float x5=(float)(x);
				
				if(x3==0)
				{
					x3=(float)(0.0001);
				}
				o=(float)(((float)((x1-x2)/x3)*x4)+x5);
			
				for(j=0;j<=g;j++)
				{
					float y1= (float)(j);
				float y2= (float)(x);
				float y3= (float)(m1);
				float y4= (float)(m2);
				float y5= (float)(y);
					o1=(float)(((float)((y1-y2)/y4)*y3)+y5);
					//cout << o1 << endl;
					if((i==y && j==x) || (i==b && j==a))
					{
						ar[i][j]='*';
					}
					else
					{
						if(y==b && i==y&& j<w1 && j>a*x/w1)
						{
							ar[i][j]='*';
						}
						else if(x==a && j==x && (i<h1) && (i>y*b/h1) )
						{
							ar[i][j]='*';
						}
						
						else 
						{	
							int k=floor((float)((o+(float)(0.5))));
							if((i<=h1) && (i>=((y*b)/h1)) && k<=w1 && k>=(a*x/w1))
							{
								ar[i][k]='*';
							}	
							int c=floor((float)((o1+(float)(0.5))));
							if((c<=h1) && (c>=((y*b)/h1)) && j<=w1 && j>=(a*x/w1))
							{
								ar[c][j]='*';
							}
							
						}
					}
				}
				
			}	
}
int trianglecheck(int x,int y,int a, int b,int p,int q)
{
	
	int x1=a-x;
	int y1=b-y;
	int d1=sqrt((x1*x1)+(y1*y1));
	int x2=p-x;
	int y2=q-y;
	int d2=sqrt((x2*x2)+(y2*y2));
	int x3=p-a;
	int y3=q-b;
	int d3=sqrt((x3*x3)+(y3*y3));
	if(d1<(d2+d3) && d2<(d1+d3) && d3<(d1+d2))
	{
		return 1;
	}
	else
	{
		cout << "Triangle does not exist !!" << endl;
		return 0;
	}
}

