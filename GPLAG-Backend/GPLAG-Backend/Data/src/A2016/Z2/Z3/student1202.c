#include <stdio.h>
#define BR_EL 10
/*ogranicenje je unos od 10 tacaka*/
int main() {
/*	printf("Zadaća 2, Zadatak 3");*/
int i,j,k,br_el;
int provjera = 0;
int niz1[BR_EL], niz2[BR_EL];
/*provjera ispravnosti unosa broja tacaka i ispravnosti koordinata */
do{
printf("Unesite broj tacaka: ");
scanf("%d", &br_el);
if(br_el<=0 || br_el>10)printf("Pogresan unos\n");}
while(br_el<=0 || br_el>10);
for(i=0; i<=br_el-1;i++) {
	printf("Unesite %d. tacku: ",i+1);
	scanf("%d %d", &niz1[i], &niz2[i]);
	if(niz1[i]<0 || niz1[i]>=20|| niz2[i]<0 || niz2[i]>=20){printf("Pogresan unos\n");i--;}
/*poredjene niz1 i niza 2 kojim smo prosli for petljom,nakon ugnjezdene petlje koja definise prosto 20*20,sa i i j */	
}
for(i=0;i<20;i++){
	for(j=0;j<20;j++) {
		for(k=0;k<br_el;k++){
			if(j==niz1[k] && i==niz2[k]){
	    	provjera=1;
	    	printf("*");
		    break;
			}
		}
		    if (provjera == 0)printf(" ");  /*ukoliko je provjera nula nizovi su razliciti od i i j pa se ispisuje razmak*/
		    else provjera =0;
}
printf("\n"); /*nakon zavrsetka j pa k petlje prelazimo u novi red i ispitujemo za slijedecuu tacku(ukoliko je unesena)*/
}
	return 0;
}
