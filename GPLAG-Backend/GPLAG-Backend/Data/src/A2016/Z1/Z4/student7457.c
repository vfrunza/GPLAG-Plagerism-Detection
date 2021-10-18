#include <stdio.h>
void razmak(int razmak){
	int i;
	for(i=0; i<razmak; i++)
		printf(" ");
	printf("*");
}
int Razmak(int razmak){
	int i;
	if(razmak<=0)
		return 0;
	for(i=0; i<razmak; i++)
		printf(" ");
	printf("*");
	return 1;
}
int main() {
	//printf("Zadaća 1, Zadatak 4");
	int broj,i,j,k;
	do{
		printf("Unesite broj n: ");
		scanf("%d", &broj);
		if(broj<=0 || broj>50)
			printf("Pogresan unos\n");
	}while(broj<=0 || broj>50);
	//zbog limitacija nacina na koji sam uradio zadatak, potrebno je da ispis za 1 hard kodiram
	if(broj==1){
		printf("***");
		return 0;
	}
	//for za redove
	for(i=0, j=2*broj-3, k=-1; i<broj; i++, j-=2, k+=2){
		razmak(i);
		Razmak(j);
		Razmak(k);
		Razmak(j);
		printf("\n");
	}
	return 0;
}
