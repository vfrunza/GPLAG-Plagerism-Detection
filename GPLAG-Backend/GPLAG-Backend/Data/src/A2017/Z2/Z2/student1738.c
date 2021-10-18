#include <stdio.h>

int main()
{
	int A[100], n, i,B[1000], j, b, C[1000], br=1,v=0;
	
	printf("Unesite velicinu niza: ");
	
	do
	{
		scanf("%d", &n);
	}while(n<0 || n>100);
	
	printf("Unesite clanove niza: ");
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	j=0;
	
	for(i=n-1; i>=0; i--)
	{
		b = A[i];
		
		do
		{
			B[j++]=b%10;
			b=b/10;
		}while(b!=0);
	}
	
	
	C[v]=B[j-1];
	
	for(i=j-2;i>=0;i--)
	{
		if(B[i+1]==B[i])
		br++;
		else
		{
			C[v+1]=br;
			v+=2;
			C[v]=B[i];
			br=1;
		}
	}
	
	if (br != 0) 
	{
		C[v+1] = br;
		v += 2;
		C[v] = B[0];
	}
	
	printf("Finalni niz glasi: \n");
	
	for(i=0;i<v;i++)
	printf("%d ",C[i]);
	
	return 0;
}
