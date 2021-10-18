#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 20

int main() {
	int mat[max][max], i, j, br, x,y;
	printf("Unesite broj tacaka: ");
	scanf ("%d", &br);
	while(br<1 || br>10)
	{
		printf ("Pogresan unos \n");
		printf("Unesite broj tacaka: ");
     	scanf ("%d", &br);
	}
	for (i=0; i<max; i++)
		for (j=0; j<max; j++)
			mat[i][j]=0;
	for(i=0;i<br ;i++)
     {
     	printf ("Unesite %d. tacku: ", i+1);
    	scanf ("%d %d", &x,&y);
    	while (x<0 || x>19 || y<0 || y>19)
    	{
    		printf ("Pogresan unos \n");
    		printf ("Unesite %d. tacku: ", i+1);
    		scanf ("%d %d", &x,&y);
    	}
    	mat[y][x]=1;
    }
    for (i=0; i<max; i++)
    {
    	for (j=0; j<max; j++)
    	{
            if (mat[i][j]==1)
    		{
    			printf ("*");
    		}
    		else
    		{
    			printf (" ");
    		}
    	}
    	printf("\n");
    }
    return 0;
}
