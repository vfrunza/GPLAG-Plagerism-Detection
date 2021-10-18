#include <stdio.h>

int main(){
	char x;
	int suma_crnih=0,suma_bijelih=0,suma_sivih=0,suma_crvenih=0,suma_plavih=0,suma=0;
   	double pc=0,pb=0,ps=0,pp=0,pv=0;
   	
	printf("Unesite vozila: ");
	
	while(1)
	{
	scanf("%c",&x);
	
		if(x=='k'|| x=='K') 
			break;
			
			
	    else if (x=='c'|| x=='C')
		suma_crnih++;
		
		else if(x=='b'|| x=='B')
		suma_bijelih++;
		
		else if (x=='s'|| x=='S')
		suma_sivih++;
		
		else if(x=='v' || x=='V')
		suma_crvenih++;
		
		else if(x=='p' || x=='P')
		suma_plavih++;
		
		else
		printf("Neispravan unos\n");
			
		}
	

	suma=suma_crnih+suma_bijelih+suma_crvenih+suma_plavih+suma_sivih;

	printf("Ukupno evidentirano %d vozila.", suma);
	if(suma==0){
	printf("\nNajpopularnija boja je crna (%.2f%%).",pc);}
 else if(suma_crnih>=suma_bijelih && suma_crnih>=suma_crvenih && suma_crnih>= suma_plavih && suma_crnih>=suma_sivih){
	 pc=(double)suma_crnih/suma*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).",pc);
	} else if (suma_bijelih>suma_crnih && suma_bijelih>=suma_crvenih && suma_bijelih>= suma_plavih && suma_bijelih>=suma_sivih){
       pb=(double)suma_bijelih/suma*100;
	printf("\nNajpopularnija boja je bijela (%.2f%%).",pb);}
	else if (suma_crvenih>suma_crnih && suma_crvenih>suma_bijelih && suma_crvenih>=suma_plavih && suma_crvenih>suma_sivih){
		 pv=(double)suma_crvenih/suma*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",pv);
		} else if(suma_plavih>suma_crnih && suma_plavih>suma_bijelih && suma_plavih>suma_crvenih && suma_plavih>suma_sivih){
			pp=(double)suma_plavih/suma*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).",pp);	
		} else if(suma_sivih>suma_crnih && suma_sivih>suma_bijelih && suma_sivih>=suma_crvenih && suma_sivih>=suma_plavih){
			ps=(double)suma_sivih/suma*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).",ps);	
		}
	return 0;
}