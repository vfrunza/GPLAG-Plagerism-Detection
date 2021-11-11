#include <stdio.h>
#include <math.h>

int main() {
	int r,k,d,j,n,l,i;
	do {
	printf("Unesite broj redova: ");
	scanf ("%d",&r);
	} while (r>10 || r<=0);
	do{
	printf ("Unesite broj kolona: ");
	scanf("%d",&k);} while (k>10 || k<=0);
	do{
	printf ("Unesite sirinu jedne kolone: ");
	scanf ("%d",&n);} while (n>10 || n<=0);
	      for (i=0;i<2*r+1;i++){
	      	for (j=0;j<=k*n+k;j++){
	      		if (j%(n+1)==0 && i%2==0 ){printf ("+");}
	      		if (i%2==0 && j%(n+1)!=0){printf ("-");}
	      		if (i%2!=0 && j%(n+1)==0){printf ("|");}
	      		if (i%2!=0 && j%(n+1)!=0 ){printf (" ");}}
	      	printf ("\n");
	      }
	      	 
	      
	return 0;
}
