#include <stdio.h>
#include <math.h>

int main() {
	int i;
	double pc, pb, pv, pp, ps, Cuk=0, Vuk=0, Suk=0, Puk=0, Buk=0, U;
	char n;
	/*pocetak for*/
		printf("Unesite vozila: ");
	
	for(i==0; i<9999999999999999999999999; i++){
	scanf("%c", &n);
	/*bijela*/
		if(n=='b' || n=='B') {
		Buk++;
		}
	/*crvena*/
		else if(n=='v' || n=='V'){
		Vuk++;
		}
	/*plava*/
		else if(n=='p' || n=='P'){
		Puk++;
		}
	/*siva*/
		else if(n=='s' || n=='S') {
			Suk++;
			}
	/*crna*/
		else if(n=='c' || n=='C'){
			Cuk++;
		}
		
	/*kraj*/
		else if(n=='k' || n=='K'){
		break;
		}
		/*nesto drugo*/
		
		else{
			printf("Neispravan unos \n");
		}
	
	
		}
		/*kraj petlje*/
   
	U=Cuk+Suk+Puk+Vuk+Buk;
	printf("Ukupno evidentirano %g vozila.", U);
	if(Cuk==0 && Vuk==0 && Buk==0 && Puk==0 && Suk==0) printf("\nNajpopularnija boja je crna (0.00%%).");
	/*crna*/
	else if(Cuk>=Vuk && Cuk>=Buk && Cuk>=Puk && Cuk>=Suk){
	pc=100/U*Cuk;
	printf("\nNajpopularnija boja je crna (%.2f%%). ", pc);
	}
	/*bijela*/
	else if(Buk>=Cuk && Buk>=Vuk && Buk>=Puk && Buk>=Suk){
	 pb=100/U*Buk;
	 printf("\nNajpopularnija boja je bijela (%.2f%%).", pb);
	}
	/*siva*/
	else if(Suk>=Cuk && Suk>=Vuk && Suk>=Puk && Suk>=Buk){
	 ps=100/U*Suk;
	 printf("\nNajpopularnija boja je siva (%.2f%%).", ps);
	}
	/*crvena*/
	else if(Vuk>=Cuk && Vuk>=Buk && Vuk>=Puk && Vuk>=Suk){
	pv=100/U*Vuk;
	printf("\nNajpopularnija boja je crvena (%.2f%%).", pv);
	}
    /*plava*/
	else if(Puk>=Cuk && Puk>=Vuk && Puk>=Buk && Puk>=Suk){
	 pp=100/U*Puk;
	 printf("\nNajpopularnija boja je plava (%.2f%%).", pp);
	}
	
	return 0;
}
