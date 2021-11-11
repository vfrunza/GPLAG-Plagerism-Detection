#include <stdio.h>
#include <math.h>

int main() {
	
	char znak, p = '%';
	int crna = 0, crvena = 0, siva = 0, plava = 0, bijela = 0;
	float rez = 0,temp,eps=0.0001;
	float postotak = 0;
	
	printf("Unesite vozila: ");
	
	for(;;){
		scanf("%c", &znak);
	if(znak == 'C' || znak == 'c') crna++;
		else if(znak == 'B' || znak == 'b') bijela++;
		else if(znak == 'S' || znak == 's') siva++;
		else if(znak == 'V' || znak == 'v') crvena++;
		else if(znak == 'P' || znak == 'p') plava++;
		else if(znak == 'K' || znak == 'k')break;
		else if(znak == '\n') continue;
		else {
			printf("Neispravan unos\n");
			continue;
		}
	}
	
	rez = crna + siva + bijela + plava + crvena;
	printf("Ukupno evidentirano %.0f vozila.\n", rez);
	
	if(crna >= bijela && crna >= siva && crna >= crvena && crna >= plava){
		if(rez<eps) postotak = 0; 
		else {
                temp=crna;
                postotak=(temp/rez)*100.0;
                }
		printf("Najpopularnija boja je crna (%.2f", postotak);
	}
	
	else if(siva >= crna && siva >= bijela && siva >= crvena && siva >= plava){
		if(rez<eps) postotak = 0;
		 else {
                temp=siva;
                postotak=(temp/rez)*100.0;
                }
		printf("Najpopularnija boja je siva (%.2f", postotak);
	}
	else if(bijela >= crna && bijela >= siva && bijela >= crvena && bijela >= plava){
		if(rez<eps) postotak = 0;
		 else{
                temp=bijela;
                postotak=(temp/rez)*100.0;
                }
		printf("Najpopularnija boja je bijela (%.2f", postotak);
	}
	
	 else if(crvena >= bijela && crvena >= siva && crvena >= crna && crvena >= plava){
		if(rez<eps) postotak = 0;
		 else {
                temp=crvena;
                postotak=(temp/rez)*100.0;
           }
		printf("Najpopularnija boja je crvena (%.2f", postotak);
	}
	
	else if(plava >= bijela && plava >= siva && plava >= crvena && plava >= crna){
		if(rez<eps) postotak = 0;
		 else{
               temp=plava;
               postotak=(temp/rez)*100.0;
            }
		printf("Najpopularnija boja je plava (%.2f", postotak);
	}
	
	printf("%c).",p);
	return 0;
}
