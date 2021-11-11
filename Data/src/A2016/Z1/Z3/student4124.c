#include <stdio.h>
#define C,c /* -crna */
#define B,b /* -bijela */
#define S,s /* -siva */
#define V,v /* -crvena */
#define P,p /* -plava */
#define K,k /* -kraj unosa */


int main() {
    
   char a;
   int brojac=0,brCrnih=0,brBijelih=0,brSivih=0,brCrveni=0,brPlavih=0;
   printf("Unesite vozila: ");
   while(1){
       scanf("%c",&a);
       brojac++;
   
    if(a=='c' || a=='C') brCrnih++;
	else if (a=='b'|| a=='B') brBijelih++;
	else if(a=='s' || a=='S') brSivih++;
	else if(a=='v' || a=='V') brCrveni++;
	else if(a=='p' || a=='P') brPlavih++;
	else if(a=='k' || a=='K') 
	{
		
		brojac--;
		break; 
	}
	else 
	{
		printf("Neispravan unos\n");
		brojac--;
	}
   }
	float postoCrni=(brCrnih*1.0/(brojac))*100.;
	float postoBijeli=(brBijelih*1.0/(brojac))*100.;
	float postoSivih=(brSivih*1.0/(brojac))*100.;
	float postoCrveni=(brCrveni*1.0/(brojac))*100.;
	float postoPlavi=(brPlavih*1.0/(brojac))*100.;
	if (brojac == 0)
	{
		postoCrni = 0.00;
	}
	printf("Ukupno evidentirano %d vozila.\n",brojac);
	if((brCrnih>=brBijelih) && (brCrnih>=brSivih) && (brCrnih>=brCrveni) && (brCrnih>=brPlavih))
	printf("Najpopularnija boja je crna (%.2f%).",postoCrni);
	else if((brBijelih>=brCrnih) && (brBijelih>=brSivih) && (brBijelih>=brCrnih)&&(brBijelih>=brPlavih))
	printf("Najpopularnija boja je bijela (%.2f%).",postoBijeli);
	else if((brSivih>=brCrnih)&&(brSivih>=brBijelih)&&(brSivih>=brCrveni)&&(brSivih>=brPlavih))
	printf("Najpopularnija boja je siva (%.2f%).",postoSivih);
	else if((brCrveni>=brCrnih)&&(brCrveni>=brBijelih)&&(brCrveni>=brSivih)&&(brCrveni>=brPlavih))
	printf("Najpopularnija boja je crvena (%.2f%).",postoCrveni);
	else if((brPlavih>=brCrnih)&&(brPlavih>=brBijelih)&&(brPlavih>=brSivih)&&(brPlavih>=brCrveni))
	printf("Najpopularnija boja je plava (%.2f%).",postoPlavi); 
	
	return 0;
}
