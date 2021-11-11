#include <stdio.h>

int main() {
	char boja='d';
	int crna=0,bijela=0,siva=0,crvena=0,plava=0,ukupno=0,max=0;
	float procenat=0;
	int foo=0;
	
	int pcrna=0;
	int pbijela=0;
	int psiva=0;
	int pcrvena=0;
	int pplava=0;
	
	
	crna=0;
	bijela=0;
	siva=0;
	crvena=0;
	plava=0;
	ukupno=0;
	max=0;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&boja);
		if(boja=='c' || boja=='C'){crna++;ukupno++;}
		else if(boja=='b' || boja=='B'){bijela++;ukupno++;}
		else if(boja=='s' || boja=='S'){siva++;ukupno++;}
		else if(boja=='v' || boja=='V'){crvena++;ukupno++;}
		else if(boja=='p' || boja=='P'){plava++;ukupno++;}
		else if(boja!='k' && boja!='K'){printf("Neispravan unos\n");}
	}
	while (boja!='k' && boja!='K');
	max=crna;
	if(bijela>max){max=bijela;}
	if(siva>max){max=siva;}
	if(crvena>max){max=crvena;}
	if(plava>max){max=plava;}
	if (ukupno!=0){procenat=max*100.0/ukupno;}else {pcrna=1; procenat=0.0;}
	
	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	if(crna==max){printf("Najpopularnija boja je crna (%.2f%%).\n",procenat);}
	else if(bijela==max){printf("Najpopularnija boja je bijela (%.2f%%).\n",procenat);}
	else if(siva==max){printf("Najpopularnija boja je siva (%.2f%%).\n",procenat);}
	else if(crvena==max){printf("Najpopularnija boja je crvena (%.2f%%).\n",procenat);}
	else if(plava==max){printf("Najpopularnija boja je plava (%.2f%%).\n",procenat);}
	return 0;
}
