#include <stdio.h>

int main() {
	 int i,j,red,kol,sir,a,b,c,d,n,k;
	 do{
	 	printf("Unesite broj redova: ");
	 	scanf("%d",&red);
	 	}while (red<=0 || red>10);
	 do{
	 	printf("Unesite broj kolona: ");
	 	scanf("%d",&kol);
	 	}while (kol<=0 || kol>10);
	 do{	
	 	printf("Unesite sirinu jedne kolone: ");
	 	scanf("%d",&sir);
	 } while(sir<=0 || sir>10);
	 a=kol+1;
	 b=sir*kol;
	 c=(a+b);
	 d=(2*red+1);
    n=sir+1;	
    k=0;
	 for(i=0;i<d;i++){
	 	for(j=0;j<c;j++){
	 		if(i%2==0 && (j==0 || j==n)) printf("+");
	 		if(i%2==0 && j>k && j<n) printf("-");
	 		if(i%2==1 && (j==0 || j==n)) printf("|");
	 		if(i%2==1 && j>k && j<n) printf(" ");
	 		if(j==n){
	 			n=n+sir+1;
	 			k=k+sir+1;
	 		}
	 		
	 	}
		 
		 printf("\n");
		 k=0;
		 n=sir+1;
		

	 }
	return 0;
}
