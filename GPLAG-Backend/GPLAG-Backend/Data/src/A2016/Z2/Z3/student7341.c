#include <stdio.h>

int main() {
int  x[20], y[20],i,j,k,n,m, ispravno;

printf("Unesite broj tacaka: ");
 scanf("%d", &n);
 while(n<=0 || n>10){
 	printf("Pogresan unos\n");
 	printf("Unesite broj tacaka: ");
 	scanf("%d", &n);
 }
 /*unos koordinata tacaka*/	
 	for (k=0;k<n;k++){
 	     printf("Unesite %d. tacku: ", k+1);
	     scanf("%d %d", &x[k],&y[k]);
	while ((x[k]<0 || x[k]>19) || (y[k]>19 || y[k]<0))
	{printf("Pogresan unos ");
	 printf("\nUnesite %d. tacku: ", k+1);
	 scanf("%d %d", &x[k],&y[k]);}}


	for (m=0; m<20; m++){
		for(i=0;i<20;i++){
			ispravno=0;
			for(j=0;j<n;j++){
				if (i==x[j] && m==y[j]){
					ispravno=1;
			    }}
			    if(ispravno==1)
			    printf("*");
			    else printf(" ");
			    }
		
		printf("\n");
		}
	
	

return 0;
}
 	
 	
 	