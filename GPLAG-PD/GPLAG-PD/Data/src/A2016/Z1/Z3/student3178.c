#include <stdio.h>

int main() {
int broj=0,crna=0,bijela=0,siva=0,crvena=0,plava=0;
float procenat=0;
char boja;


printf("Unesite vozila: ");
	
	do{
			scanf("%c", &boja);
		
	if( boja != 'C' && boja != 'c' && boja != 'B' && boja != 'b' && boja != 'S' && boja != 's' 
	&& boja != 'P' && boja != 'p' && boja != 'V' && boja != 'v' && boja != 'K' && boja != 'k'){
	printf("Neispravan unos\n");}


	
	if(boja=='C' || boja=='c'){
		crna++;
		broj++;}
	if(boja=='B' || boja=='b'){
		bijela++;
		broj++;
		}
if(boja=='S' || boja=='s'){
		siva++;
		broj++;
		}
	if(boja=='V' || boja=='v'){
		crvena++;
		broj++;
		}
	if(boja=='P' || boja=='p'){
		plava++;
		broj++;
		}
	
}
while( boja != 'K' && boja != 'k' );




	printf("Ukupno evidentirano %d vozila.\n", broj);
 if(crna>=bijela && crna>=siva && crna>=crvena  && crna>=plava){
if(broj==0){ broj=1;}
 	procenat=(100*crna)/(float)broj;
 	printf("Najpopularnija boja je crna (%.2f%%).", procenat);
 }

 else if(bijela>=crna && bijela>=siva && bijela>=crvena  && bijela>=plava){
 procenat=(100*bijela)/(float)broj;
 	printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
 }
  else if(siva>=crna && siva>=bijela && siva>=crvena  && siva>=plava){
 procenat=(100*siva)/(float)broj;
 	printf("Najpopularnija boja je siva (%.2f%%).", procenat);
 }
  else if(crvena>=crna && crvena>=bijela && crvena>=siva  && crvena>=plava){
 procenat=(100*crvena)/(float)broj;
 	printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
 }
  else  if(plava>=crna && plava>=bijela && plava>=siva  && plava>=crvena){
 procenat=(100*plava)/(float)broj;
 	printf("Najpopularnija boja je plava (%.2f%%).", procenat);
 }
 
	return 0;
}



