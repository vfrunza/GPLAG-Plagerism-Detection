#include <stdio.h>

int main()
{

	double Mat[100][100];
	int i,j;
	int m,n;
	int tep=1,cirk=1;
    
        printf("Unesite M i N: ");
	    scanf("%d %d",&m,&n);
	
	while(m>100 || m<1 || n<1 || n>100)
	{   
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
	    scanf("%d %d",&m,&n);
	}
    
    printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%lf",&Mat[i][j]);


	for(i=0; i<m-1; i++)
		for(j=0; j<n-1; j++)
			if(Mat[i][j]!=Mat[i+1][j+1]) tep=0;


	if(tep==1) {
		for(i=0; i<m-1; i++)
			if(Mat[i+1][0]!=Mat[i][n-1]) cirk=0;
	}




	if(tep==1) {
		if(cirk==1) printf("Matrica je cirkularna");
		else
			printf("Matrica je Teplicova");
	} else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
