#include <stdio.h>

int main() {
int x[10],y[10],tacka,j,k,l;
int i = 0;
greska:printf("Unesite broj tacaka: ");
scanf("%d", &tacka);
if(tacka < 1 ||tacka > 10){
	printf("Pogresan unos\n");
	goto greska;
}
while(i < tacka){
	unos:printf("Unesite %d. tacku: ", (i+1));
	scanf("%d %d", &x[i],&y[i]);
    if(x[i] < 0 || x[i] > 19 || y[i] < 0 || y[i] > 19 ){
		printf("Pogresan unos\n");
		goto unos;
	}
	i++;
}
for(j = 0; j < 20;j++){
	for(k = 0;k < 20;k++){
		for(l = 0;l < tacka;l++){
			if(x[l] == k && y[l]==j){
			printf("*");
			break;
			}
		}
		if(l == tacka){
			printf(" ");
			
		}
	}
	printf("\n");
}


	return 0;
}
