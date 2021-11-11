#include <stdio.h>

int main() {
	int redni_broj=1,kraj_petlje=0,ukupan_broj_vozila=0, crna=0, bijela=0, siva=0, crvena=0, plava=0, max, redni_max, i=1;
	int redni_crne=0, redni_crvene=0, redni_sive=0,redni_plave=0,redni_bijele=0;
	
	char slovo_auta;
	double procenat=0;
	printf("Unesite vozila: ");
	while(!kraj_petlje){
		
		scanf("%c",&slovo_auta);
		
		
		if(slovo_auta =='C' || slovo_auta == 'c') {
			crna++;
			if(crna==1) {
				redni_crne+=redni_broj;
				++redni_broj;
					
			}
		}	
				
		else if(slovo_auta =='B' || slovo_auta == 'b') {
			bijela++;
			if(bijela==1) {
				redni_bijele+=redni_broj;
				++redni_broj;
			}
				
		}
				
		else if(slovo_auta =='S' || slovo_auta == 's') {
			siva++;
			if(siva==1){
				redni_sive+=redni_broj;
				++redni_broj;
			}
			
		}
			
		else if(slovo_auta =='V' || slovo_auta == 'v')  {
			crvena++;
			if(crvena==1) {
				redni_crvene+=redni_broj;
				++redni_broj;
			
				
			}
			
		}
			
		else if(slovo_auta =='P' || slovo_auta == 'p')  {
			plava++;
				if(plava==1) {
				redni_plave+=redni_broj;
				++redni_broj;
			}
			
		}
			
		else if(slovo_auta !='K' && slovo_auta != 'k' ) 
			printf("Neispravan unos\n");
		else if(slovo_auta =='K' || slovo_auta == 'k') 
			kraj_petlje=1;
		
	i++;
	}
		
	ukupan_broj_vozila = crna+bijela+siva+crvena+plava;
	max=crna;
	redni_max=redni_crne;

	//Provjeravaje kojeg auta ima najvise, i ako ih je vise, onda ciji je redni broj manji
	if(bijela>=max) {
		if(bijela>max) {
			max=bijela;
			redni_max=redni_bijele;
		}
			
		else if (bijela==max) {
			if(redni_bijele<redni_max){
				max=bijela;
				redni_max=redni_bijele;
			}
		}
	}
	
	if(siva>=max) {
		if(siva>max){
			max=siva;
			redni_max=redni_sive;
		}
		
		else if (siva==max) {
			if(redni_sive<redni_max){
				max=siva;
				redni_max=redni_sive;
			}
		}
	}
	
	if(crvena>=max) {
		if(crvena>max) {
			max=crvena;
			redni_max = redni_crvene;
		}
			
		else if (crvena==max) {
			if(redni_crvene<redni_max){
				max=crvena;
				redni_max = redni_crvene;
			}
		}
	}

	if(plava>=max) {
		if(plava>max) {
			max=plava;
			redni_max=redni_plave;
		}
		
		else if (plava==max) {
			if(redni_plave<redni_max){
				max=plava;
				redni_max=redni_plave;
			}
		}
	}
	
	//Racunanje procenta najpopularnijeg automobila
	if(ukupan_broj_vozila==0)
		procenat=0.00;
	else
		procenat = max*100.0/ukupan_broj_vozila ;
	printf("Ukupno evidentirano %d vozila.\n",ukupan_broj_vozila);
	

	//Najpopularnija boja je... 
	if(max==crna && redni_max == redni_crne) 
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
	else if(max==siva && redni_max == redni_sive)
		printf("Najpopularnija boja je siva (%.2f%%).",procenat);
	else if(max==bijela && redni_max == redni_bijele)
		printf("Najpopularnija boja je bijela (%.2f%%).",procenat);
	else if(max==crvena && redni_max == redni_crvene)
		printf("Najpopularnija boja je crvena (%.2f%%).",procenat);
	else if(max==plava && redni_max == redni_plave)
		printf("Najpopularnija boja je plava (%.2f%%).",procenat);
	return 0;
}
