#include <stdio.h>
#include<stdlib.h>

int main() {
	char boja ;
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, ukupno=0 ;
	printf("Unesite vozila: ");

	while(1==1)
	
	{
	scanf("%c", &boja);
	if(boja=='c' || boja=='C')
	{crna++;
	ukupno++;}
	else if(boja=='b' || boja=='B')
	{bijela++;
	ukupno++;}
	else if(boja=='s' ||boja=='S')
	{siva++;
	ukupno++;}
	else if(boja=='v' || boja=='V')
	{crvena++;
	ukupno++;}
	else if(boja=='p' || boja=='P')
	{plava++;
	ukupno++;}
	else if(boja=='k'|| boja=='K')
	break;
	else if (boja=='\n')
	ukupno--;
	else 
	printf("Neispravan unos\n");
	}
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	 if(ukupno==0)
	printf("Najpopularnija boja je crna (0.00%%). \n");	
	else if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava)
	printf("Najpopularnija boja je crna (%.2f%%).\n", (float)crna/ukupno*100);
	
	
	 else if(bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava)
	printf("Najpopularnija boja je bijela (%.2f%%).\n", (float)bijela/ukupno*100);
    
	else if(siva>bijela && siva>=crna && siva>=crvena && siva>=plava)
	printf("Najpopularnija boja je siva (%.2f%%).\n", (float)siva/ukupno*100);
	
	else if(crvena>bijela && crvena>siva && crvena>crna && crvena>=plava)
	printf("Najpopularnija boja je crvena (%.2f%%).\n", (float)crvena/ukupno*100);
		
	
	else if(plava>bijela && plava>siva && plava>crvena && plava>crna)
	{printf("Najpopularnija boja je plava (%.2f%%).\n", (float)plava/ukupno*100);
	
	}
	
	return 0;}