#include <stdio.h>
provjerava da li su matrice B i C sastavljene od istih elemenata kao matrica A, 
pri čemu se ti elementi trebaju ponavljati isti broj puta.

int main() {
	
	int M,N,i,j,matA[100][100],matB[100][100],matC[100][100],nizA[100],nizB[100],nizC[100],nizAp[100],nizBp[100],nizCp[100],k=0,k1=0,m=0,m1=0,n=0,n1=0,minA,minB,minC,temp,brA=0,brB=0,brC=0,
		nizAbr[10000],nizBbr[10000],nizCbr[10000],isto=1;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}while (M<0 || M>100 || N<0 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&matA[i][j]);
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&matB[i][j]);
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&matC[i][j]);
	}
	/* pretvaranje matrice A u niz*/
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
			{
				nizA[k]=matA[i][j];
				k++;
			}
	}
	
	for(i=0;i<k;i++)
	{
		minA=i;
		for(j=i+1;j<k;j++)
		{
			if (nizA[j]<nizA[minA])
				minA=j;
		}
		temp=nizA[i];
		nizA[i]=nizA[minA];
		nizA[minA]=temp;
	}
	if (k==1)
	{
		nizAp[k1]=nizA[0];
		k1++;
	}
	else
	{
		for(i=0;i<k-1;i++)
		{
			if(nizA[i]!=nizA[i+1])
			{
				nizAp[k1]=nizA[i];
				k1++;
			}
		}
	}
	
	for(i=0;i<k1;i++)
	{
		for(j=0;j<k;j++)
		{
			if (nizAp[i]==nizA[j])
				brA++;
		}
		nizAbr[i]=brA;
	}
	
	/*pretvaranje matrice B u niz*/
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			nizB[m]=matB[i][j];
			m++;
		}
	}
	
	for(i=0;i<m;i++)
	{
		minB=i;
		for(j=i+1;j<m;j++)
		{
			if (nizB[j]<nizB[minB])
				minB=j;
		}
		temp=nizB[i];
		nizB[i]=nizB[minB];
		nizB[minB]=temp;
	}
	if (m==1)
	{
		nizBp[m1]=nizB[0];
		m1++;
	}
	else
	{
		for(i=0;i<m-1;i++)
		{
			if (nizB[i]!=nizB[i+1])
			{
				nizBp[m1]=nizB[i];
				m1++;
			}	
		}
	}
	for(i=0;i<m1;i++)
	{
		for(j=0;j<m;j++)
		{
			if (nizBp[i]==nizB[j])
				brB++;
		}
		nizBbr[i]=brB;
	}
	
	/*pretvaranje matrice C u niz*/
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			nizC[n]=matC[i][j];
			n++;
		}
	}
	
	for(i=0;i<n;i++)
	{
		minC=i;
		for(j=i+1;j<n;j++)
		{
			if (nizC[j]<nizC[minC])
				minC=j;
		}
		temp=nizC[i];
		nizC[i]=nizC[minC];
		nizC[minC]=temp;
	}
	if (n==1)
	{
		nizCp[n1]=nizC[0];
		n1++;
	}
	else
	{
		for(i=0;i<n-1;i++)
		{
			if (nizC[i]!=nizC[i+1])
			{
				nizCp[n1]=nizC[i];
				n1++;
			}	
		}
	}	
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n;j++)
		{
			if (nizCp[i]==nizC[j])
			{
				brC++;
			}
		}
		nizCbr[i]=brC;
	}

	if (k1!=m1 || k1!=n1)
	{
		printf("NE");
		return 0;
	}
	
	for(i=0;i<k1;i++)
	{
		if (nizAp[i]!=nizBp[i] || nizAp[i]!=nizCp[i])
			isto=0;
		
		else if (nizAbr[i]!=nizBbr[i] || nizAbr[i]!=nizCbr[i])
			isto=0;
	}
	
	if (isto==1)
		printf("DA");
	else 
		printf("NE");
	
	return 0;
}