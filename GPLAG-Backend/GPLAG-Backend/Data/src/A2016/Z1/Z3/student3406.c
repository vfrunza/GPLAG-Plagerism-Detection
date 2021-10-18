#include <stdio.h>

int main() {
	char slova;
	int brojac=0, crvena=0, crna=0, bijela=0, siva=0, plava=0, max=0;
	double procenat;
	printf("Unesite vozila: ");
	do {
		
		scanf("%c", &slova);
		if (slova!='c' && slova!='C' && slova!='S' && slova!='B' && slova!='s' && slova!='b' && slova!='P' && slova!='p' && slova !='V' && slova !='v' && slova!='\n' && slova!='k' && slova!='K') {
		printf("Neispravan unos\n");
		 }
		 
		if (slova=='c' || slova=='C' || slova=='S' || slova=='B' || slova=='s' || slova=='b' || slova=='P' || slova=='p' || slova=='v' || slova=='V') {
		brojac++; }
		 	if (slova=='V' || slova=='v') crvena++;
		 	else if (slova=='p' || slova == 'P') plava++;
		 	else if (slova=='c' || slova=='C') crna++;
		 	else if (slova=='s' || slova=='S') siva++;
		 	else if (slova=='b' || slova=='B') bijela++;
		
	} while (slova!='K' && slova!='k');

    printf("Ukupno evidentirano %d vozila.\n", brojac);
    if(brojac==0)
    printf("Najpopularnija boja je crna (0.00%%).\n");
    else {
   
    
    max=crna; 
    if (bijela>max)  max=bijela;
    if (siva>max)  max=siva;
    if (crvena>max) max=crvena;
    if(plava>max) max=plava;
    
    procenat=((double)max/brojac)*100;
    
    if (max==crna)
    printf("Najpopularnija boja je crna (%.2f%%).\n", procenat);
    else if (max==bijela)
    printf("Najpopularnija boja je bijela (%.2f%%).\n", procenat);
    else if (max==siva)
    printf("Najpopularnija boja je siva (%.2f%%).\n", procenat);
    else if(max==crvena)
    printf("Najpopularnija boja je crvena (%.2f%%).\n", procenat);
    else
    printf("Najpopularnija boja je plava (%.2f%%).\n", procenat);
  
   
}
 
    
	return 0;
} 
