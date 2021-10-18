#include <stdio.h>
#include <math.h>

int main() {
	int i,j,nizC[100], nizB[1000], k=0, brojEl,cifra,br=1,step,el,temp=-1,tempEl;

	/* Unos niza */
	printf("Unesite velicinu niza: ");
	scanf("%d",&brojEl);
	printf("Unesite clanove niza: ");
	for(i=0; i<brojEl; i++){
		step=0;
		scanf("%d",&el);
		if(el>=0){
			nizC[i]=el;
		
		/* Broj cifara */
			while(el>=10){
				el/=10;
				step++;
			}
		}
		
        /* Rastavljanje na cifre */
		tempEl=nizC[i];
		for(j=0; j<=step; j++){
			cifra=tempEl/pow(10,(step-j));
			tempEl-=cifra*pow(10,(step-j));
		
		/* Brojac istih cifara */
			if(cifra==temp){
				br++;
				k-=2;
			}
			else br=1;
			
		/* Niz B */
		    nizB[k]=cifra;
		    k++;
		    nizB[k]=br;
		    k++;
		    
		    temp=cifra;
		}
	}
	
	/* Ispis */
	printf("Finalni niz glasi:\n");
	for(i=0; i<k; i++){
		printf("%d ",nizB[i]);
	}
	return 0;
}
