#include <stdio.h>

int main() {
	int s1,v1,s2,v2,A[100][100],B[100][100],i,j,pom[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&s1,&v1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<v1;i++)
	{
	 for(j=0;j<s1;j++)
	  scanf("%d",&A[i][j]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&s2,&v2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<v2;i++)
	{
	 for(j=0;j<s2;j++)
	  scanf("%d",&B[i][j]);
	}
	if(s1!=v2 || v1!=s2) 
	{
	 printf("NE\n");
	 return 1;
	}
	for(i=0;i<v1;i++)
	{
	 for(j=0;j<s1;j++)
	 {
	 	pom[j][v1-i-1]=A[i][j];
	 }
	}
	for(i=0;i<v2;i++)
	{
	 for(j=0;j<s2;j++)
	 {
	  if(B[i][j]!=pom[i][j])
	  {
	   printf("NE\n"); 
	   return 1;
	  }
	 }
	}
	printf("DA\n");
	return 0;
}
