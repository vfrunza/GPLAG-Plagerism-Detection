#include <stdio.h>

int main() {
	int vel,pom1, pom2, i, j;
	int a,b,c;
	int mat[20][20];
	do
	{
		printf("Unesite broj tacaka: ");
		a++;
		scanf("%d", &vel);
		if(vel<=0 || vel>10) printf("Pogresan unos\n");
	} while(vel<=0 || vel>10);
    for(i=0; i<20; i++)
    {
    	for(j=0; j<20; j++)
    	

     mat[i][j]=0;
    }

    for(i=0; i<vel; i++)
    {
    	while(0==0)
    	{
    		printf("Unesite %d. tacku: ", i+1);
    	    scanf("%d %d", &pom1, &pom2);
    	    c-=i;
    	    if(pom1<0 || pom2<0 || pom1>19 || pom2>19) printf("Pogresan unos\n");
    	    else break;
    	    a+=b;
    	}
    	mat[pom2][pom1]=1;
    }
    for(i=0; i<20; i++)
    {
    	for(j=0; j<20; j++)
    	{
    		if(mat[i][j]==1) printf("*");
    		else printf(" ");
    	} printf("\n");
    }
	return 0;
}
