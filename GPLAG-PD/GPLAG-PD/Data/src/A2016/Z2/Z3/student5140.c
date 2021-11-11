#include <stdio.h>

int main() {
	int br,i,j,k,niz1[19],niz2[19],brojac=0;
    do{
    printf("Unesite broj tacaka: ");
	scanf("%d",&br);
	if(br>10 || br<1)
	printf("Pogresan unos\n");
    }while(br>10 || br<1);
	for(i=0; i<br; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &niz1[i], &niz2[i]);
		if(niz1[i]<0 || niz1[i]>19 || niz2[i]<0 || niz2[i]>19){
		printf("Pogresan unos\n");
		i--;
		}
	}
	for(j=0; j<20; j++){
		for(i=0; i<20; i++){
			for (k=0;k<br;k++){
				if(niz1[k]==i && niz2[k]==j){
					brojac++;
					break;
				}
			}
		    	if(brojac>0) 
				printf("*");
				else 
				printf(" ");
				brojac=0;
		}
		printf("\n");
	}
			
	return 0;
}
