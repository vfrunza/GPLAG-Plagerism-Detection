#include <stdio.h>
#define x 100

int main() 
{
	int A[x][x], B[x][x], C[x][x], i, j, a[x*x], b[x*x], c[x*x], M, N, y=0, temp, min;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}while(M<0 || N<0 || M>100 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<N; i++) for(j=0; j<M; j++) scanf("%d", &A[i][j]);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<N; i++) for(j=0; j<M; j++) scanf("%d", &B[i][j]);
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<N; i++) for(j=0; j<M; j++) scanf("%d", &C[i][j]);
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			a[y]=A[i][j];
			y++;
		}
	}
	
	y=0;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			b[y]=B[i][j];
			y++;
		}
	}
	
	y=0;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			c[y]=C[i][j];
			y++;
		}
	}
	
	for(i=0; i<M*N; i++)
	{
		min=i;
		for(j=i+1; j<M*N; j++)
		{
			if(a[j]<a[min]) min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	
	for(i=0; i<M*N; i++)
	{
		min=i;
		for(j=i+1; j<M*N; j++)
		{
			if(b[j]<b[min]) min=j;
		}
		temp=b[i];
		b[i]=b[min];
		b[min]=temp;
	}
	
	for(i=0; i<M*N; i++)
	{
		min=i;
		for(j=i+1; j<M*N; j++)
		{
			if(c[j]<c[min]) min=j;
		}
		temp=c[i];
		c[i]=c[min];
		c[min]=temp;
	}
	
	j=0;
	
	for(i=0; i<M*N; i++)
	{
		if(a[i]==b[i] && b[i]==c[i]) continue;
		else j++;
	}
	
	if(j>0) printf("NE\n");
	else printf("DA\n");
	
	return 0;
}