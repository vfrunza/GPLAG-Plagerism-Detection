#include <stdio.h>

int main() {
	/*printf("Zadaća 2, Zadatak 3");*/
	int mat[11][2],tmp,temp,koliko,i,j,k,odradio;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&koliko);
	if(koliko<1 || koliko >10)printf("Pogresan unos\n");
	}while(koliko<1 || koliko>10);
	for(i=0;i<koliko;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&temp, &tmp);
		if(temp<0 || temp>19 || tmp<0 || tmp>19){
			i--; printf("Pogresan unos\n");continue;
		}
		mat[i][0]=tmp;
		mat[i][1]=temp;
	}
	for( i=0;i<20;i++){
		for(j=0;j<20;j++){
			odradio=0;
			for(k=0;k<koliko;k++){
				if(mat[k][0]==i && mat[k][1]==j){
					printf("*");odradio=1;break;
					}
				else if(k==koliko-1 && odradio==0)printf(" ");
				}
		}
	printf("\n");
	}
	return 0;
}
