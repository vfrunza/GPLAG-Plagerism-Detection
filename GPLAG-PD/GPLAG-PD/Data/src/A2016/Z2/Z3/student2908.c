#include <stdio.h>
#define visina 20
#define sirina 20

int main () {
	int brojtac, i, j, mat[visina][sirina]={{0}}, kordy, kordx;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&brojtac);
			if(brojtac<=0 || brojtac>10) {
				printf("Pogresan unos\n");
				continue;
			}
			for(i=0;i<brojtac;i++){
				printf("Unesite %d. tacku: ",i+1);
			    scanf("%d %d",&kordy,&kordx);
			    mat[kordx][kordy]=1;
			    if(kordx>19 || kordy>19 || kordx<0 || kordy<0) {
					printf("Pogresan unos\n");
					i--;
					mat[kordx][kordy]=0;
			    }
			}
	}while(brojtac>10 || brojtac<=0 || kordx>19 || kordy>19 || kordx<0 || kordy<0); 
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(mat[i][j]==1)
				printf("*");
			if(mat[i][j]==0)
				printf(" ");
		}
		printf("\n");
	}
	return 0;	
}