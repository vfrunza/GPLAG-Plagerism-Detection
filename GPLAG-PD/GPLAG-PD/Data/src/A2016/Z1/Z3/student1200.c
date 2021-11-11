#include <stdio.h>

int main()
{
	char znak;
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, br=0, max=0;
	float postotak=0.0;
	printf("Unesite vozila: ");
	while(1) {
		scanf("%c", &znak);
		if(znak=='k' || znak=='K') break;
		else if(znak=='c' || znak=='C'  ) {
			crna++;
			br++;
			if(crna>max) {
				max=crna;
				znak='c';
			}


		} else if(znak=='b' || znak=='B') {
			bijela++;
			br++;
			if(bijela>max) {
				max=bijela;
				znak='b';
			}
			}else if(znak=='s' || znak=='S') {
				siva++;
				br++;
				if(siva>max) {
					max=siva;
					znak='s';
				}
			} else if(znak=='v' || znak=='V') {
				crvena++;
				br++;
				if(crvena>max) {
					max=crvena;
					znak='v';
				}

			} else if(znak=='p' || znak=='P') {
				plava++;
				br++;
				if(plava>max) {
					max=plava;
					znak='p';
				}
			}
			else printf("Neispravan unos\n");
	}
		
	
		printf("Ukupno evidentirano %d vozila.\n",br);
		if(max==crna) {
			if(br==0)
				postotak=0.00;
			else 
				postotak=(crna/(float) br)*100;
			printf("Najpopularnija boja je crna (%.2f%%).", postotak);
			
		} else if(max == bijela) {
			if(br==0)
				postotak=0.00;
			else
				postotak=(bijela/(float) br)*100;
			printf("Najpopularnija boja je bijela (%.2f%%).",postotak); 
			
		} else if(max==siva) {
			if(br==0)
				postotak=0.00;
			else
				postotak=(siva/(float) br)*100;
			printf("Najpopularnija boja je siva (%.2f%%).",postotak);
			
		} else if(max==crvena) {
			if(br==0)
				postotak=0.00;
			else
				postotak=(crvena/(float) br)*100;
			printf("Najpopularnija boja je crvena (%.2f%%).",postotak);
			
		} else if(max==plava) {
			if(br==0)
				postotak=0.00;
			else
				postotak=(plava/(float) br)*100;
			printf("Najpopularnija boja je plava (%.2f%%).",postotak);
			
		}

			return 0;
	}
