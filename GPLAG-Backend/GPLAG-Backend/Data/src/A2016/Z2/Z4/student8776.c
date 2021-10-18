#include <stdio.h>

int main()
{
	int i,j,k,l,z;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int temp3=0;
	int br1=0, br2=0, br3=0, br4=0, br5=0;

	
	int m,n;

	float mat[100][100];

	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || m >100 || n<=0 || n>100) printf("Pogresan unos!\n");

		

	} while (m<=0 || n<=0 || m>100 || n>100);


	printf("Unesite elemente matrice: ");
	for(k=0; k<m; k++) {
		for(l=0; l<n; l++) {
			scanf("%f", &mat[k][l]);
	
		}
	}

	for(i=0; i<m-1; i++) {
		for(j=0; j<n-1; j++) {

			if(mat[0][0]==mat[i][j])
				temp=1;
			if(mat[i][j]==mat[i+1][j+1])
				temp1=1;
			if(mat[i][j]==mat[i+1][j+1] )
				temp2=1;

		}

	}
	for(z=0; z<m-2; z++){
		if (mat[z][n-2]==mat[z+1][0])
		temp3=1;
	
	 
	}


   if(temp==1 && temp1==1 && temp2==1 && temp3==1){br1++;
   printf("Matrica je cirkularna");}
	
	if(m==1 && n==1){br2++;
	printf("Matrica je cirkularna");}
	if(m==1 && n!=1){br3++;
	printf("Matrica je cirkularna");}
	
	
 if(m!=1 && n==1){br4++;
	printf("Matrica je Teplicova");}
	

	 
	 if(temp==1 && temp1==1 && temp2==1  && temp3==0){br5++;

		printf("Matrica je Teplicova");}


	if(br1==0 && br2==0 && br3==0 && br4==0 && br5==0 )
	printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
