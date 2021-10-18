#include <stdio.h>

int main() {
	int br_redova,br_kolona,sirina_kolone,i,j;
	
	do {
		printf("Unesite broj rodeova: "); scanf("%d",&br_redova);
		printf("Unesite broj kolona: "); scanf("%d",&br_kolona);
		printf("Unesite sirinu jedne kolone: "); scanf("%d",&sirina_kolone);
	}while((br_redova>0 && br_redova<=10) && (br_kolona>0 && br_kolona<=10) && (sirina_kolone<0 && sirina_kolone<=10));
	
	for(i=0;i<=br_redova;i++) {
		for(j=0;j<=br_kolona*(1+sirina_kolone);j++) {
			if(i=)
		}
	}
	
	
	return 0;
}
