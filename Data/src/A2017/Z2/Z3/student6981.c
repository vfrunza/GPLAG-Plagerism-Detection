#include <stdio.h>
#include <math.h>
#define e 0.0001
int main() {
	
	int i,j,S1,S2,V1,V2;
    double A[100][100],B[100][100];
    
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &S1, &V1);
    printf("Unesite clanove matrice A: ");
    for(i=0;i<V1;i++)
    {
    	for(j=0;j<S1;j++)
    	{
    		scanf("%lf", &A[i][j]);
    	}
    }
    
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &S2, &V2);
    printf("Unesite clanove matrice B: ");
    for(i=0;i<V2;i++)
    {
    	for(j=0;j<S2;j++)
    	{
    		scanf("%lf", &B[i][j]);
    	}
    }
    
    if(S1!=V2 || S2!=V1)
    {
    	printf("NE\n");
    	return 1;
    }	
    else
    {
    	for(i=0;i<V2;i++)
    	{
    		for(j=0;j<S2;j++)
    		{
    			if(A[V1-j-1][i]-B[i][j]>e)
    			{
    				printf("NE\n");
    				return 1;
    			}
    		}
    	}
    }
    
    printf("DA\n");
    
	
	return 0;
}
