#include <stdio.h>

int main() {
	int  m,n,i,j,cirk=1,temp=1;
	double mat[100][100];

	printf("Unesite M i N: ");
	do
	{
	scanf("%d" "%d", &m,&n);
	while(m<=0 || m>100 || n<=0 || n>100)
	{
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d" "%d", &m,&n);
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
} while(m<0 || m>100 || n<0 || n>100);

	 
	 for(i=1;i<m;i++)
	 {
	 		if(mat[i][0]!=mat[i-1][n-1])
	 		{
	 			cirk=0;
	 		}
	 	for(j=1;j<n;j++)
	 	{
	
	      if(mat[i][j]!=mat[i-1][n-1])
	 	{
	 		cirk=0;
	 		break;
	 	}
	 	else if( mat[i][j]!=mat[i-1][n-1] && j==0 )
	 	{
	 		cirk=0;
	 		break;
	 	}
	 	}
	 	}  
	 	
	 	
	 		 for(i=1;i<m;i++)
	 {
	 	for(j=1;j<n;j++)
	 
	 	{
	 	if(mat[i][j]!=mat[i-1][j-1])
	 	{
	 		temp=0;
	 		break;
	 	} 
	 else	if(mat[i][j]!=mat[i-1][j]-1 && j==0)
	 	{
	 		temp=0;
	 		break;
	 	}
	 else	if(i==0 && j==n-1 && mat[i][j]!=mat[i+1][j]+1)
	 	{
	 		temp=0;
	 		break;
	 	}
	 	}
	 }
	 
	 
	 if(n==1 && m==1)
	 {
	 	cirk=1;
	 }
	 else if(m==1)
	 {
	 	temp=1;
	 }
	 else if(n==1)
	 {
	 	temp=1;
	 }
	 
	 
	 
	 if(cirk==1)
	 {
	 	printf("Matrica je cirkularna\n");
	 }
	 else if(temp==1)
	 {
	 printf	("Matrica je Teplicova\n ");
	 }
	 else if(cirk!=1 && temp!=1)
	 {
	 	printf("Matrica nije ni cirkularna ni Teplicova\n");
	 }
	 	
	 	
	 return 0;
	 		
	 	
	 }
	
