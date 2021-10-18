#include <stdio.h>

int main() {
	char x;
	int brojac1=0,brojac2=0,brojac3=0,brojac4=0,brojac5=0,y=0;
	printf("Unesite vozila: ");
	
	do{
		scanf("%c",&x);
		if(x=='P' || x=='p')
		{
			brojac1++;
		}
		else if(x=='V' || x=='v')
		{
			brojac2++;
		}
		else if(x=='S' || x=='s')
		{
			brojac3++;
		}
		else if(x=='B' || x=='b')
		{
			brojac4++;
		}
		else if(x=='C' || x=='c')
		{
			brojac5++;
		}
		if(x!='B' && x!='b' && x!='C' && x!='c' && x!='V' && x!='v' && x!='P' && x!='p' && x!='S' && x!='s' && x!='K' && x!='k')
		{
			printf("Neispravan unos\n");
		}
	}
	 while(x!='K' && x!='k');
	 
	 y=brojac5+brojac4+brojac3+brojac2+brojac1;
	 printf("Ukupno evidentirano %d vozila.\n",y);
	 float max=0,pom=0;
	 
	 if(brojac1>=brojac2 && brojac1>=brojac3 && brojac1>=brojac4 && brojac1>=brojac5)
	 {
	 	max=brojac1;
	 	pom=max/y*1.0;
	 	pom=pom*100;
	 	printf("Najpopularnija boja je plava (%.2f%%).\n",pom);
	 }
	 else if(brojac2>=brojac1 && brojac2>=brojac3 && brojac2>=brojac4 && brojac2>=brojac5)
	 {
	 	max=brojac2;
	 	pom=max/y*1.0;
	 	pom=pom*100;
	 	printf("Najpopularnija boja je crvena (%.2f%%).\n",pom);
	 }
	 else if(brojac3>=brojac1 && brojac3>=brojac2 && brojac3>=brojac4 && brojac3>=brojac5)
	 {
	 	max=brojac3;
	 	pom=max/y*1.0;
	 	pom=pom*100;
	 	printf("Najpopularnija boja je siva (%.2f%%).\n",pom);
	 	
	 }
	 else if(brojac4>=brojac1 && brojac4>=brojac2 && brojac4>=brojac3 && brojac4>=brojac5)
	 {
	 	max=brojac4;
	 	pom=max/y*1.0;
	 	pom=pom*100;
	 	printf("Najpopularnija boja je bijela (%.2f%%).\n",pom);
	 }
	 else if(brojac5>=brojac1 && brojac5>=brojac2 && brojac5>=brojac3 && brojac5>=brojac4)
	 {
	 	max=brojac5;
	 	pom=max/y*1.0;
	 	pom=pom*100;
	 	printf("Najpopularnija boja je crna (%.2f%%).",pom);
	 }
	return 0;
}
