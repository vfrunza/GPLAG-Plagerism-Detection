#include <stdio.h>

int main() {
	int redovi,kolone,sirina,istinar=0,istinak=0,istinas=0,j,k,i,c;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&redovi);
	if (redovi>0 && redovi<=10) istinar=1;}
		while (istinar==0 );
	do{		
	printf("Unesite broj kolona: ");
	scanf("%d",&kolone);
	if(kolone<=10 && kolone>0) istinak=1;}
	while (istinak==0);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);
	if(sirina>0 && sirina<=10) istinas=1;
	}
	while ( istinas==0);
	
 	for (i=0;i<redovi;i++){
		for(j=0;j<kolone;j++){
			printf("+");
		for (k=0;k<sirina;k++){
			printf("-");
		}
		if(j==kolone-1) {
			printf("+\n");
		}
	}
		for (c=0;c<kolone;c++) {                                           
			printf("|") ;
			for(k=0;k<sirina;k++){
				printf(" ");
			}
		if (c==kolone-1){
			printf("|\n");
		}
		}	
 	}
 		for(j=0;j<kolone;j++){
			printf("+");
		for (k=0;k<sirina;k++){
			printf("-");
		}
 		
		if(j==kolone-1) {
			printf("+");
		}
 		}
	return 0;
}
                              