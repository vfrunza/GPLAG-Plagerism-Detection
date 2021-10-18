#include <stdio.h>

int main() {


	
	char boja;
	int plava=0, crvena=0, bijela=0, crna=0, siva=0,ukupno=0,max; 
	float procent;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&boja);
		
		if(boja=='c' || boja=='C' || boja=='v' || boja=='V' || boja=='P' || boja=='p' || boja=='b' || boja=='B' || boja=='s' || boja=='S' || boja=='k' || boja=='K' )
   		{
		if(boja=='c' || boja=='C')
		crna++;
		else if(boja=='b' || boja=='B')
		bijela++;
		else if(boja=='s' || boja=='S')
		siva++;
		else if(boja=='v' || boja=='V')
		crvena++;
		else if(boja=='P' || boja=='p')
		plava++;
		
		
		}
		else {printf("Neispravan unos\n");}
	}while(boja != 'k' && boja !='K');
	ukupno=plava+crvena+bijela+siva+crna;

	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	max=crna;
	if(crvena>max)
		max=crvena;
		
	
	if(bijela>max)
		max=bijela;
		
	
	if(plava>max)
		max=plava;
		
	
	if(siva>max)
		max=siva;
			
	procent = (float)max/ukupno*100;

	if(ukupno==0){
		procent=0;
		printf("Najpopularnija boja je crna (0.00%%).");
		}
	else if(max==plava) {printf("Najpopularnija boja je plava (%.2f%%).",procent);}
	else if(max==crvena) {printf("Najpopularnija boja je crvena (%.2f%%).",procent);}
	else if(max==bijela) {printf("Najpopularnija boja je bijela (%.2f%%).",procent);}
	else if(max==siva) {printf("Najpopularnija boja je siva (%.2f%%).",procent);}
	else if(max==crna) {printf("Najpopularnija boja je crna (%.2f%%).",procent);}

	

	return 0;
}
