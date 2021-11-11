#include <stdio.h>

int main() {
	int broj_tacaka,brojac,i,j;
	char niz[20][20];

	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	while(broj_tacaka<1 || broj_tacaka>10)
	{printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d", &broj_tacaka);}
	for(i=0; i<20; i++){
	for(j=0; j<20;j++)
	{niz[i][j]=' ';}}
	for(brojac=0; brojac<broj_tacaka; brojac++){
	printf("Unesite %d. tacku: ",brojac+1);
	scanf("%d",&i);
	scanf("%d",&j);
	while(i<0 || j<0 || j>19 || i>19){
	printf("Pogresan unos\n");
	printf("Unesite %d. tacku: ",brojac+1);
	scanf("%d",&i);		
	scanf("%d",&j);}
	niz[i][j]='*';}
	
	for(i=0; i<20; i++){
	for(j=0; j<20;j++){
	printf("%c",niz[j][i]);}
	printf("\n");}
	return 0;}