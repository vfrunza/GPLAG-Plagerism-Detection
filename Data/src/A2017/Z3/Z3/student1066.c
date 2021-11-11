#include <stdio.h>
#include<math.h>
int izbaci_cifre(int niz1[],int n1,int niz2[],int n2)
{
	int i,j,n=0,x,y,br=0,ost,u;
	double e;
	for(i=0;i<n2;i++)
	{
		if(niz2[i]<0 || niz2[i]>9)
		{
			return 0;
		}
		for(j=i+1;j<n2;j++)
		{
			if(niz2[i]==niz[j])
			{
				return 0;
			}
		}
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
		x=niz1[i];
		while(x>0)
		{
			y=x%10;
			n=n+1;
			x=x/10;
			if(y==niz2[j])
			{
				e=pow(10,n);
				u=e;
				ost=niz1[i]%u;
				y=y*(u/10);
				niz1[i]=niz1[i]-ost;
				niz1[i]=niz1[i]/10;
				ost=ost-y;
				niz1[i]=niz1[i]+ost;
				n=0;
				x=niz1[i];
			}
			
			
		}
		}
	}
}

int main() {
	
	return 0;
}
