#include <stdio.h>
#include <math.h>
#define E 00000000000000000.1
int main()
{
	int m,n,i,j,l,p;
	double matrica[100][100];
	printf ("Unesite M i N: ");
	scanf ("%d %d",&m,&n);

	while (m<=0 || m>100 || n>100 || n<=0) {
		printf ("Pogresan unos! \n");
		printf ("Unesite M i N: ");
		scanf ("%d %d",&m,&n);
	}
	l=1;
	p=1;

	if (m>0 && m<=100 && n<=100 && n>0) {
		printf ("Unesite elemente matrice: ");
		
		
		for (i=0; i<m; i++) {
			for (j=0; j<n; j++) {
				scanf ("%lf",&matrica[i][j]);}}

				
				for (i=0; i<m-1; i++) {
					for (j=0; j<n-1; j++) {
						
							if(fabs(matrica[i][j]-matrica[i+1][j+1])>E)
							{

								l=0;

							}
						}

					}
			
  if(l==1){
		
			for (i=0; i<m-1; i++) {
			

					if (fabs(matrica [i][n-1]-matrica[i+1][0])>E) {
						p=0;

					}
				
			}}
			if (l==1)
			{
			if(p==1)	printf ("Matrica je cirkularna");
			


			else {
				printf ("Matrica je Teplicova ");
			}}

			else{
				printf ("Matrica nije ni cirkularna ni Teplicova");
			}
}
		

	return 0;
}