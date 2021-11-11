#include <stdio.h>
int main() {
	int a,d,b,c,A[100][100],B[100][100],i,j;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&d,&a);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<a;i++)
	    for(j=0;j<d;j++)
    	scanf("%d",&A[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&c,&b);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<b;i++)
		for(j=0;j<c;j++)
		scanf("%d",&B[i][j]);
	if(a!=c||b!=d)
	{
	  printf("NE");
	  return 0;
	}
	  for(i=0;i<a;i++)
	   for(j=0;j<d;j++)
        if(A[i][j]!=B[j][a-1-i]) 
        {
        	printf("NE");
        	return 0;
        }
      printf("DA");
      return 0;
}
