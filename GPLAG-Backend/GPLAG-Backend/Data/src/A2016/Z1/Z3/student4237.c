#include <stdio.h>

int main() {
	char ch;
	float sumC=0, sumB=0, sumS=0, sumV=0, sumP=0, neradinista=0;
	float SUM;
	float a, b, c, d, e;

	printf("Unesite vozila: ");
	
	do {
		
		scanf("%c", &ch);
		
		if (ch=='C' || ch=='c') sumC++;
		else if (ch=='B' || ch=='b') sumB++;
		else if (ch=='S' || ch=='s') sumS++;
		else if (ch=='V' || ch=='v') sumV++;
		else if (ch=='P' || ch=='p') sumP++;
		else if (ch=='K' || ch=='k') neradinista++;
		else { printf("Neispravan unos\n");}
		
	} while (ch!='K' && ch!='k');
	 
	 SUM=sumC+sumB+sumS+sumV+sumP;
	 printf("Ukupno evidentirano %g vozila.\n", SUM);
	 
	 
	a=(sumC/SUM)*100;
	b=(sumB/SUM)*100;
	c=(sumS/SUM)*100;
	d=(sumV/SUM)*100;
	e=(sumP/SUM)*100;
	 
	if(SUM==0) 
	printf("Najpopularnija boja je crna (0.00%).");
	else if (sumC>=sumB && sumC>=sumS && sumC>=sumV && sumC>=sumP)  
	printf("Najpopularnija boja je crna (%.2f%).",   a);
	else if (sumB>=sumS && sumB>=sumV && sumB>=sumP)  
	printf("Najpopularnija boja je bijela (%.2f%).", b);
	else if (sumS>=sumV && sumS>=sumP)  
	printf("Najpopularnija boja je siva (%.2f%).",   c);
	else if (sumV>=sumP) 
	printf("Najpopularnija boja je crvena (%.2f%).", d);
	else  
	printf("Najpopularnija boja je plava (%.2f%).",  e);
	
	 
	 
	return 0;
}
