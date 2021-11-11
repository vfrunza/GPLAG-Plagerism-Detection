#include <stdio.h>

int main() {
	char unos;
	int ukupnoAutomobila=0, crnaUkupno=0, bijelaUkupno=0, sivaUkupno=0, crvenaUkupno=0,plavaUkupno=0;
	float procenatNajpopularnije;
	
	printf("Unesite vozila: ");
	
	do {
	 scanf("%c",&unos);
	 
	 if(unos!= 'K' && unos!= 'k') {
	   if(unos== 'C' || unos== 'c') {
		ukupnoAutomobila=ukupnoAutomobila + 1;
		crnaUkupno=crnaUkupno + 1;
	   } else if(unos =='B' || unos =='b') {
			ukupnoAutomobila=ukupnoAutomobila+1;
			bijelaUkupno=bijelaUkupno+1;
		} else if(unos=='S' || unos=='s') {
				ukupnoAutomobila=ukupnoAutomobila+1;
			sivaUkupno=sivaUkupno+1;
		} else if(unos == 'V' || unos == 'v') {
					ukupnoAutomobila=ukupnoAutomobila+1;
					crvenaUkupno=crvenaUkupno+1;
		} else if(unos == 'P' || unos == 'p') {
						ukupnoAutomobila=ukupnoAutomobila+1;
						plavaUkupno=plavaUkupno+1;
		} else {
			printf("Neispravan unos\n");
		}
	  }
	} 
	while(unos!= 'K' && unos!= 'k');
			
	printf("Ukupno evidentirano %d vozila.\n", ukupnoAutomobila);
	
	if(crnaUkupno>=bijelaUkupno && crnaUkupno>=sivaUkupno && crnaUkupno>=crvenaUkupno && crnaUkupno>=plavaUkupno){
		if(ukupnoAutomobila==0) {
			procenatNajpopularnije = 0;
		} else {
			procenatNajpopularnije = (crnaUkupno*(float)100)/ukupnoAutomobila;	
		}
		printf("Najpopularnija boja je crna (%.2f%).", procenatNajpopularnije);
		
	}	else if(bijelaUkupno>=sivaUkupno && bijelaUkupno>=crnaUkupno && bijelaUkupno>=crvenaUkupno && bijelaUkupno>=plavaUkupno) {
			if(ukupnoAutomobila==0) {
				procenatNajpopularnije = 0;
			} else {
				procenatNajpopularnije = (bijelaUkupno*(float)100)/ukupnoAutomobila;	
			}
			printf("Najpopularnija boja je bijela (%.2f%).", procenatNajpopularnije);
			
		}	else if(sivaUkupno>=crnaUkupno && sivaUkupno>=bijelaUkupno && sivaUkupno>=crvenaUkupno && sivaUkupno>=plavaUkupno) {
				if(ukupnoAutomobila==0) {
			      procenatNajpopularnije = 0;
		        } else {
			      procenatNajpopularnije = (sivaUkupno*(float)100)/ukupnoAutomobila;	
		        }
				printf("Najpopularnija boja je siva (%.2f%).", procenatNajpopularnije);
				
			}	else if(crvenaUkupno>=sivaUkupno && crvenaUkupno>=bijelaUkupno && crvenaUkupno>=crnaUkupno && crvenaUkupno>=plavaUkupno) {
					if(ukupnoAutomobila==0) {
						procenatNajpopularnije = 0;
					} else {
						procenatNajpopularnije = (crvenaUkupno*(float)100)/ukupnoAutomobila;	
					}
					printf("Najpopularnija boja je crvena (%.2f%).", procenatNajpopularnije);
					
				}	else {
						if(ukupnoAutomobila==0) {
							procenatNajpopularnije = 0;
						} else {
							procenatNajpopularnije = (plavaUkupno*(float)100)/ukupnoAutomobila;	
						}
						printf("Najpopularnija boja je plava (%.2f%).",procenatNajpopularnije);
					}
		
	return 0;
}
