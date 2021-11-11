#include <stdio.h>

void ubaci (int * nizf,int size1)
{
	int i,cf,a;
	int suma=0;
	
	for (i=size1-1;i>=0;i--)
	{
		nizf [2*i]=nizf[i];
	}
	
	for (i=0;i<size1*2;i++)
	{
		
		if (i%2==1) /*neparni*/
		{
			a=nizf[i-1];
			while (a!=0)
			{
				cf=a%10;
				suma+=cf;
				a/=10;
			}
			
			if (suma>=0)
			{
				suma=suma;
			}
			else if (suma<0)
			{
				suma=-suma;
			}
			nizf[i]=suma;
			suma=0;
		}
		
	}
}

int  izbaci (int * nizf,int size2)
{
	int i,j,k;
	int st,nd,temp;
	for (i=0;i<size2;i++)
	{
		st=0;
		nd=1;
		for (j=0;j<500;j++)
		{
			temp=st+nd;
			st=nd;
			nd=temp;
			if (nizf [i]==temp)
			{
				for (k=i;k<size2-1;k++)
				{
					nizf [k]=nizf [k+1];
				}
				size2--;
				i--;
				break;
			}
		}
	}
	return size2;
	
}


int main() 
{
	int niz[50];
	int i,cl;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++)
	{
		scanf ("%i",&niz[i]);
	}
	 ubaci(niz,10);
	 cl=izbaci(niz,20);
	 
	 printf ("Modificirani niz glasi: ");
	 for (i=0;i<cl;i++)
	 {
	 	if (i<(cl-1))
	 	{
	 		printf ("%i, ",niz[i]);
	 	}
	 	else 
	 	{
	 		printf ("%i.",niz[i]);
	 	}
	 	
	 }
	return 0;
}