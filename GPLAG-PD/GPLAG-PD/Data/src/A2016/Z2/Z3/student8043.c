#include <stdio.h>
int main() {
	int broj_tacaka=0,a,b,k;
	char koordinatni_sistem[20][20];
	printf("Unesite broj tacaka: ");
	scanf("%d", &broj_tacaka);
	while(broj_tacaka<1 || broj_tacaka>10) {printf("Pogresan unos\n"); printf("Unesite broj tacaka: "); scanf("%d", &broj_tacaka);}
	for(a=0; a<20; a++) {
	for(b=0; b<20; b++)
	koordinatni_sistem[a][b]=' ';}
	for(k=0;k<broj_tacaka;k++) {
	printf("Unesite %d. tacku: ", k+1);
	scanf("%d",&a);
	scanf("%d",&b);
	if(a<0 || a>19 || b<0 || b>19) {
		printf("Pogresan unos\n");
		k--;}
	koordinatni_sistem[a][b]='*';}

	for(a=0;a<20;a++) {
	for(b=0;b<20;b++)
	printf("%c",koordinatni_sistem[b][a]);
	printf("\n");}
	
	
	return 0;
}
