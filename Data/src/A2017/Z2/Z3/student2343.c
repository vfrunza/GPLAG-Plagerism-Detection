#include <stdio.h>

int main() {
	int A[100][100],B[100][100];
	int temp,m,n,a,b;
	int isEqual=1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &m, &n);
	printf("Unesite clanove matrice A: ");
	for(a=0;a<m;a++)
	 for(b=0;b<n;b++)
	{scanf("%d", &A[a][b]);}
    
	
	for(a=0;a<m;a++)
	{for(b=a+1;b<n;b++){
		temp=A[a][b];
		A[a][b]=A[b][a];
		A[b][a]=temp;
	}
	}
	for(a=0;a<m;a++)
	{for(b=0;b<n/2;b++){
		temp=A[a][b];
		A[a][b]=A[a][n-1-b];
		A[a][n-1-b]=temp;
	}
	}
	for(a=0;a<m;a++)
	 {for(b=0;b<n;b++)
	 printf("%2d",A[a][b]);
	 printf("\n"); }
	 printf("\n");
	 
 printf("Unesite sirinu i visinu matrice B: ");
	 scanf("%d %d",&m,&n);
	 printf("Unesite clanove matrice B: ");
      for(a=0;a<m;a++);
	   for(b=0;b<n;b++);
	  {scanf("%d", &B[a][b]);}
		 



	 for(a=0;a<m;a++)
	 {for(b=0;b<n;b++)
	 	if(A[a][b] != B[a][b]){
	 	isEqual=0;
	 		break;
	  }
	 }
	 
	 if(isEqual == 0)
	 {printf("NE");}
	 else printf("DA");


return 0;

	 	

}
