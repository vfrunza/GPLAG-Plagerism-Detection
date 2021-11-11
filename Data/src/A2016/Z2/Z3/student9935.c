#include <stdio.h>

int main() {
	int broj_tacaka,i,j,k,niz_1[10]={0},niz_2[10]={0},temp=0;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	if(broj_tacaka<=10 && broj_tacaka>=1){
		break;
	}
	printf("Pogresan unos\n");
	}while(broj_tacaka>10 || broj_tacaka<1);
				for(i=0;i<broj_tacaka;i++){
					printf("Unesite %d. tacku: ",i+1);
					scanf("%d %d",&niz_2[i],&niz_1[i]);
					if(niz_1[i]<0 || niz_1[i]>19 || niz_2[i]<0 || niz_2[i]>19){
						printf("Pogresan unos\n");
						i--;
					}
				}
				for(i=0;i<20;i++){
					for(j=0;j<20;j++){
						for(k=0;k<broj_tacaka;k++){
							if(i==niz_1[k] && j==niz_2[k]){
								printf("*");
								temp=1;
								break;
							}							
						}
						if(temp!=1)
							printf(" ");
							temp=0;
					}
					printf("\n");
				}
	return 0;
}