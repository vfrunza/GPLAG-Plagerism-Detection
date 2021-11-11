#include <stdio.h>

int main() {
	int n,a,i,j;
	int niz1[10],niz2[10];
	int zvjezdica;

	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<1 || n>10) printf("Pogresan unos\n");

	}
	while(n<1 || n>10);

	for(a=0;a<n;a++){

		printf("Unesite %d. tacku: ", a+1);
		scanf("%d %d", &niz1[a],&niz2[a]);
		if(niz1[a]>19 || niz1[a]<0 || niz2[a]>19 || niz2[a]<0){

		 printf("Pogresan unos\n");
		 a--;
		}
	}


	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			zvjezdica=0;
            for(a=0;a<n;a++){
            	
            
			if(j==niz1[a] && i==niz2[a]){
				 printf("*");
				 zvjezdica=1;
				 break;
			}
            }
            
			if(zvjezdica==0) printf(" ");

		}

		printf("\n");
	}
	return 0;
}
