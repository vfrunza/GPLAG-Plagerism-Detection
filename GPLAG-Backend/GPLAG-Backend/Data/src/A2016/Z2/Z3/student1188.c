#include <stdio.h>

int main() {
	int n=0,i=0,j=0,k=0,niz1[20],niz2[20],p=0,q=0;
			
			/*Unos broja tacaka*/
			do{	printf("Unesite broj tacaka: ");
				scanf("%d",&n);
					if((n>10)||(n<=0)){
						printf("Pogresan unos\n");
					
						}}while((n>10)||(n<=0));
						
		/*Unos tacaka*/
		for(i=0;i<n;i++){
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&niz1[i],&niz2[i]);
			if(((niz1[i]<0)||(niz1[i]>=20))||((niz2[i]<0)||(niz2[i]>=20))){
				printf("Pogresan unos\n");
				i--;
			}
		}
						for(i=0;i<20;i++){
						for(j=0;j<20;j++){
						for(k=0;k<n;k++){
					if((niz1[k]==j) && (niz2[k]==i) && (p==0) ){
						printf("*");
						p++;
					}
					else  {q++;}
				}
				if((q=(n-1))&&(p==0)) 
				printf(" ");
				p=0;
				k=0;
				q=0;
			}
			printf("\n");
		}
		
			return 0;
}
