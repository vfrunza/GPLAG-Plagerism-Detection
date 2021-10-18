#include <stdio.h>

int main() {
	char boja;
	unsigned int crna=0, bijela=0, siva=0, crvena=0, plava=0, i=0, max;
	double postotak=0;
	printf("Unesite vozila: ");
	while(scanf("%c", &boja)) {
		if(boja<97) {
			boja+=32;
		}
		if(boja=='k') {
			break;
		}
		i++;
		switch(boja) {
			case 'c':
			  crna++;
			  break;
			case 'b':
			  bijela++;
			  break;
			case 's':
			  siva++;
			  break;
			case 'v':
			  crvena++;
			  break;
			case 'p':
			  plava++;
			  break;
			default:
			  printf("Neispravan unos\n");
			  i--;
			  break;
		}
	}
	printf("Ukupno evidentirano %d vozila. \n", i);
	printf("Najpopularnija boja je ");
	max=crna;
	 if(bijela>max) 
	   max=bijela;
	 if(siva>max)
	   max=siva;
	 if(crvena>max)
	   max=crvena;
	 if(plava>max)
	   max=plava;
	 
	 if(max==crna)
	   printf("crna");
	 else if(max==bijela)
	   printf("bijela");
	 else if(max==siva)
	   printf("siva");
	 else if(max==crvena)
	   printf("crvena");
	 else
	   printf("plava");
	   
	 if(i!=0) {
	 	postotak=max/(double)i;
	 	postotak*=100;
	 }
	 printf(" (%.2f%%).", postotak);
	return 0;
}
