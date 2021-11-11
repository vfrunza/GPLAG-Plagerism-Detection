#include <stdio.h>

int main() {
	char unos;
	int crna=0, siva=0, plava=0, crvena=0, bijela=0;
	float posto;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&unos);
		if(unos!='c' && unos!='C' && unos!='s' && unos!='S'&& unos!='p' && unos!='P' && unos!='v' && unos!='V' && unos!='b' && unos!='B' && unos!='k' && unos!='K')
			printf("Neispravan unos\n");
		if(unos=='c' || unos=='C')
			crna++;
		if(unos=='s' || unos=='S')
			siva++;
		if(unos=='p' || unos=='P')
			plava++;
		if(unos=='v' || unos=='V')
			crvena++;
		if(unos=='b' || unos=='B')
			bijela++;
		if(unos=='k'|| unos=='K')
			break;
	}while(unos!='k'|| unos!='K');
	
	int ukupno=plava+bijela+crna+crvena+siva;
	float ukupno1=ukupno;
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	
	if((crna>=siva)&&(crna>=crvena)&&(crna>=plava)&&(crna>=bijela)){
		posto=crna*(100/ukupno1);
		if(ukupno==0)
			posto=0;
		printf("Najpopularnija boja je crna (%.2f%%).", posto) ;
		return 0;
	}
	if((siva>=crna)&&(siva>=crvena)&&(siva>=plava)&&(siva>=bijela)){
		posto=siva*(100/ukupno1);
		if(ukupno==0)
			posto=0;
		printf("Najpopularnija boja je siva (%.2f%%).", posto) ;
		return 0;
	}
	if((bijela>=crna)&&(bijela>=crvena)&&(bijela>=plava)&&(bijela>=siva)){
		posto=bijela*(100/ukupno1);
		if(ukupno==0)
			posto=0;
		printf("Najpopularnija boja je bijela (%.2f%%).", posto) ;
		return 0;
	}
	if((crvena>=crna)&&(crvena>=bijela)&&(crvena>=plava)&&(crvena>=siva)){
		posto=crvena*(100/ukupno1);
		if(ukupno==0)
			posto=0;
		printf("Najpopularnija boja je crvena (%.2f%%).", posto) ;
		return 0;
	}
	if((plava>=crna)&&(plava>=crvena)&&(plava>=bijela)&&(plava>=siva)){
		posto=plava*(100/ukupno1);
		if(ukupno==0)
			posto=0;
		printf("Najpopularnija boja je plava (%.2f%%).", posto) ;
		return 0;
	}
		
	
	
	return 0;
}
