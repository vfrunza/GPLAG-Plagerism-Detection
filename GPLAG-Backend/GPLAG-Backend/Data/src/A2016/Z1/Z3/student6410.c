#include <stdio.h>
int main() {
	char znak='a';
	int brojacC=0, brojacV=0, brojacB=0, brojacP=0, brojacS=0, brojac=0,brojacK=0;
float p=0;
	printf("Unesite vozila: ");
while(znak!='K' && znak!='k'){ 
  scanf("%c",&znak);
  if(znak=='C' || znak=='c') brojacC++;
  else if(znak=='V' || znak=='v') 
   brojacV++;
  else if(znak=='B' || znak=='b') 
   brojacB++;
  else if(znak=='P' || znak=='p') 
   brojacP++;
  else if(znak=='S' || znak=='s') 
   brojacS++;
  else if(znak=='K' || znak=='k') 
   brojacK++;
  else 
   printf("Neispravan unos\n");
  } 
	brojac=brojacS+brojacP+brojacB+brojacV+brojacC;
	if(brojac==0){
		printf("Ukupno evidentirano %d vozila.",brojac);
	printf("\nNajpopularnija boja je crna (0.00%)."); 
	return 0;}
else	printf("Ukupno evidentirano %d vozila.",brojac);
{
	 if(brojacC>=brojacC && brojacC>=brojacP && brojacC>=brojacB && brojacC>=brojacV){
		p=100.*brojacC/brojac;
		printf("\nNajpopularnija boja je crna (%.2f%%).",p);
	 	
	 }
		
	else if(brojacS>=brojacC && brojacS>=brojacP && brojacS>=brojacB && brojacS>=brojacV){
		p=100.*brojacS/brojac;
		printf("\nNajpopularnija boja je siva (%.2f%%).",p);
		
	}
	
	else if(brojacB>=brojacC && brojacB>=brojacP && brojacB>=brojacS && brojacB>=brojacV){
		p=100.*brojacB/brojac;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",p);
		
	}
	
	else	if(brojacP>=brojacV && brojacP>=brojacB && brojacP>=brojacC && brojacP>=brojacS){
		p=100.*brojacP/brojac;
	printf("\nNajpopularnija boja je plava (%.2f%%).",p);
		
	}
	
	else if(brojacV>=brojacC && brojacV>=brojacP && brojacV>=brojacB && brojacV>=brojacS){
		p=100.*brojacV/brojac;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",p);
		
	}
	}
	
	return 0;
}
