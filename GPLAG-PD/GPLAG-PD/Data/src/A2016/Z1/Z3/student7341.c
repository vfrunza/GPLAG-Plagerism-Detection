#include <stdio.h>

int main() {
	char boja;
	float Pc,Pp,Pcr,Ps,Pb;
    float crna, siva, bijela, plava, crvena, U;
	printf("Unesite vozila: ");
	crna=0; siva=0; bijela=0; plava=0;  crvena=0;
	do { scanf("%c", &boja);
		if(boja =='c' || boja =='C'){
			crna++;
		}
		else if(boja=='s' || boja =='S'){
			siva++ ;
		}
		else if (boja=='P' || boja=='p'){
			plava++ ;
		}
		else if (boja=='V' || boja=='v'){
			crvena++ ;
		}
		
		else if (boja=='B' || boja=='b'){
			bijela++;
		}
		else if (boja!='K' && boja!='k') {
			printf("Neispravan unos\n");
		}	
		
	}
	while (boja!='K' && boja!='k');

	
	U=bijela + crvena + crna + siva + plava;
	printf("Ukupno evidentirano %g vozila.", U);
	if (U!=0){
	Pc=(crvena/U)*100; 
	Pp=(plava/U)*100;
	Pb=(bijela/U)*100;
	Pcr=(crna/U)*100;
	Ps=(siva/U)*100;
	}
	else {
		Pc=0;
		Pp=0;
		Pb=0;
		Pcr=0;
		Ps=0;
	}
    
    if(crna>=bijela && crna>=plava && crna>=siva && crna>=crvena){
    	printf("\nNajpopularnija boja je crna (%.2f%%).", Pcr);
    }
     else if (bijela>=crvena && bijela>=plava && bijela>=siva && bijela>=crna){
     	printf("\nNajpopularnija boja je bijela (%.2f%%).", Pb);
     }
     else if (siva>=bijela && siva>=plava && siva>=crvena && siva>=crna){
     	printf("\nNajpopularnija boja je siva (%.2f%%).", Ps);
     }
     else if (crvena>=crna && crvena>=plava && crvena>=siva && crvena>=bijela){
     	printf("\nNajpopularnija boja je crvena (%.2f%%).", Pc);
     }
     else if (plava>=bijela && plava>=crvena && plava>=siva && plava>=crna){
     	printf("\nNajpopularnija boja je plava (%.2f%%).", Pp);
    	}
   
 
   
    
    

	return 0;
}
