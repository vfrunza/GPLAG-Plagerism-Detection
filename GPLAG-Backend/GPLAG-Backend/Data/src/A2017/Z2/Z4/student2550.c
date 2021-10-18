#include <stdio.h>
int main() {
    int j,i,k,m,n,mat1[100][100],mat2[100][100],mat3[100][100],niz1[100*100],brojac1[100*100]={0},brojac2[100*100]={0},brojac3[100*100]={0};
	int a=0;
	//int i,j,m=3,n=3,mat1[3][3]={1,2,3,6,6,4,3,7,-1},mat2[3][3]={-1,3,3,2,6,4,6,1,7},mat3[3][3]={3,6,7,2,6,-1,3,4,2},niz1[9],niz2[9],niz3[9],brojac1[9]={0},brojac2[9]={0},brojac3[9]={0},sigurnost=1;
	do
	{ 
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	}while(m<0 ||m>100 || n>100 || n<0);
	
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
	    scanf("%d",&mat1[i][j]);
	}
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
	    scanf("%d",&mat2[i][j]);
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
	   scanf("%d",&mat3[i][j]);
	}
	
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		niz1[a]=mat1[i][j]; a++;
		
		}
		
	}
	//Postavljanje brojaca za mat 1
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<a;k++)
			{
			if(mat1[i][j]==niz1[k]) brojac1[k]++;	
			}
		}
	}
	//Postavljanje brojaca za mat 2
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<a;k++)
			{
				if(mat2[i][j]==niz1[k]) brojac2[k]++;
			}
		}
	}
	//Postavljanje brojaca za mat 3
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<a;k++)
			{
				if(mat3[i][j]==niz1[k]) brojac3[k]++;
			}
		}
	}
	
	for(i=0;i<m*n;i++) {
		if (brojac1[i]!=brojac2[i] || brojac1[i]!=brojac3[i] || brojac2[i]!=brojac3[i])
		{
		printf("NE\n");
		return 0;
		}
	}
		 printf("DA\n");
	
	return 0;
}
