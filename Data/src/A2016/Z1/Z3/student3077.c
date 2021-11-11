#include <stdio.h>

int main() {
	char boja; int crvena=0,plava=0,bijela=0,crna=0,siva=0,ukupno=0; float procent_crvena,procent_plava,procent_bijela,procent_siva,procent_crna;
	printf("Unesite vozila: ");
	while(1){ 
      scanf("%c", &boja);
      if(boja=='K' || boja=='k') break; 
    	     else if(boja=='C' || boja=='c') {
    	     	 crna++;
    	       ukupno++;
    	     } else if(boja=='B' || boja=='b') {
    	     	bijela++;
    	     	ukupno++;
    	     } else if(boja=='S' || boja=='s') {
    	     	siva++;
    	     	ukupno++;
    	     } else if(boja=='V' || boja=='v'){
    	     	crvena++;
    	     	ukupno++;
    	     } else if(boja=='P' || boja=='p'){
    	     	plava++;
    	     	ukupno++;
    	     } else printf("Neispravan unos\n"); }
     procent_crna=((float)crna/ukupno)*100;
     procent_bijela=((float)bijela/ukupno)*100;
     procent_siva=((float)siva/ukupno)*100;
     procent_crvena=((float)crvena/ukupno)*100;
     procent_plava=((float)plava/ukupno)*100;
    
       if(procent_crna>=procent_bijela && procent_crna>=procent_siva && procent_crna>=procent_crvena && procent_crna>=procent_plava) {
      	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crna (%.2f%%).",ukupno,procent_crna);
      } else if(procent_bijela>procent_crna && procent_bijela>=procent_crvena && procent_bijela>=procent_siva && procent_bijela>=procent_plava){
      	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je bijela (%.2f%%).",ukupno,procent_bijela);
      }else if(procent_siva>procent_crna && procent_siva>=procent_crvena && procent_siva>procent_bijela && procent_siva>=procent_plava){
      	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je siva (%.2f%%).",ukupno,procent_siva);
      }else if(procent_crvena>procent_crna && procent_crvena>=procent_plava && procent_crvena>procent_siva && procent_crvena>procent_bijela){
      	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crvena (%.2f%%).",ukupno,procent_crvena);
      }else if(procent_plava>procent_crna && procent_plava>procent_bijela && procent_plava>procent_siva && procent_plava>procent_crvena){
      	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je plava (%.2f%%).",ukupno,procent_plava); 
      }else if(crna==0 && siva==0 && plava==0 && crvena==0 && bijela==0) {
        printf("Ukupno evidentirano 0 vozila.\nNajpopularnija boja je crna (0.00%).");
      } 
      	
	return 0;
}
