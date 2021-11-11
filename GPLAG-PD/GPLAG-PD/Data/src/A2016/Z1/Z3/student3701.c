#include <stdio.h>
#include <math.h>
#define GRESKA 0.0001

int main() {

	char x;
	int brojac=0, i;
	int crna=0,bijela=0,siva=0,crvena=0,plava=0;
	float max=0;
	float procenat;

	printf("Unesite vozila: ");
	do{

        scanf("%c",&x);
        
        if(x!='K'&&x!='k'&&x!='C'&&x!='c'&&x!='B'&&x!='b'&&x!='S'&&x!='s'&&x!='V'&&x!='v'&&x!='P'&&x!='p'){
            printf("Neispravan unos");
            printf("\n");
            continue;
        }brojac++;
        if(x=='C'||x=='c'){crna++;}
        if(x=='B'||x=='b'){bijela++;}
        if(x=='S'||x=='s'){siva++;}
        if(x=='V'||x=='v'){crvena++;}
        if(x=='P'||x=='p'){plava++;}

	}	while(x!='K'&&x!='k');
	printf("Ukupno evidentirano %d vozila.",brojac-1);

      
	for(i=0;i<5;i++){
        if(crna>max) max=crna;
        if(bijela>max) max=bijela;
        if(siva>max) max=siva;
        if(crvena>max) max=crvena;
        if(plava>max) max=plava;}
        
      
    if(fabs(max-crna)<GRESKA){
        if(brojac-1==0){printf("\nNajpopularnija boja je crna (0.00%%)."); return 0;}
        else{
        procenat=(max/(brojac-1))*100;
        printf("\nNajpopularnija boja je crna (%.2f%%).",procenat);
        return 0;}}
	if(fabs(max-bijela)<GRESKA){
        procenat=(max/(brojac-1))*100;
        printf("\nNajpopularnija boja je bijela (%.2f%%).",procenat);
        return 0;}
	if(fabs(max-siva)<GRESKA){
        procenat=(max/(brojac-1))*100;
        printf("\nNajpopularnija boja je siva (%.2f%%).",procenat);
        return 0;}
	if(fabs(max-crvena)<GRESKA){
        procenat=(max/(brojac-1))*100;
        printf("\nNajpopularnija boja je crvena (%.2f%%).",procenat);
        return 0;}
	if(fabs(max-plava)<GRESKA){
        procenat=(max/(brojac-1))*100;
        printf("\nNajpopularnija boja je plava (%.2f%%).",procenat);}
	return 0;
}