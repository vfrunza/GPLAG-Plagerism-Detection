#include <stdio.h>

int main() {
	int t=0, x=0, y=0, z=0, j=0, suma=0;
	char boja=0;
	float procenatc, procenatb, procenats, procenatv, procenatp;
	printf("Unesite vozila: ");
	while(boja!='k' && boja!='K') {
	scanf("%c", &boja);
	if(boja!='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='p' && boja!='P' && boja!='k' && boja!='K') {
	printf("Neispravan unos\n");
	}
	else if(boja=='c' || boja=='C' || boja=='b' || boja=='B' || boja=='s' || boja=='S' || boja=='v' || boja=='V' || boja=='p' || boja=='P'){
	
	 if(boja=='c' || boja=='C') {
		t++;suma++;}
    if(boja=='b' || boja=='B') {
		x++;suma++;}
    if(boja=='s' || boja=='S'){
		y++;suma++;}
    if(boja=='v'  || boja=='V'){
		z++;suma++;}
    if(boja=='p' || boja=='P'){
		j++;suma++;}
	}
	}
    printf("Ukupno evidentirano %d vozila.\n", suma);
	
	if(suma==0) {
	printf("Najpopularnija boja je crna (0.00%%).");
	}
	else if(t>=x && t>=y && t>=z && t>=j){
		procenatc=(t*100.00/suma);
		printf("Najpopularnija boja je crna (%.2f%%).", procenatc);
	}
	else if(x>=t && x>=y && x>=z && x>=j){
		procenatb=(x*100.00/suma);
		printf("Najpopularnija boja je bijela (%.2f%%).", procenatb);
	}
	else if(y>=t && y>=x && y>=z && y>=j){
		procenats=(y*100.00/suma);
		printf("Najpopularnija boja je siva (%.2f%%).", procenats);
	}
	else if(z>=t && z>=x && z>=y && z>=j){
		procenatv=(z*100.00/suma);
		printf("Najpopularnija boja je crvena (%.2f%%).", procenatv);
	}
	else if(j>=t && j>=x && j>=y && j>=z){
		procenatp=(j*100.00/suma);
		printf("Najpopularnija boja je plava (%.2f%%).", procenatp);
	}
		return 0;
}




