#include <stdio.h>

int main() {
	
	char jelo1,jelo2,jelo3;
	char novi_red;
	float cijena1=0,cijena2=0,cijena3=0;
	int brojac_pica=0,brojac_hamburger=0,brojac_cevapi=0;
	float max=0;
	float cijenasapopustom=0;
	
	float restoran_pica=6.8;
	float restoran_hamburger=3.3;
	float restoran_cevapi=5.0;
	
	float trovac_pica=8.0;
	float trovac_hamburger=3.0;
	float trovac_cevapi=3.9;
	
	float bistro_pica=5.3;
	float bistro_hamburger=5.0;
	float bistro_cevapi=6.0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&jelo1);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&jelo2);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&jelo3);
	scanf("%c",&novi_red);
	
	if(jelo1=='P'){cijena1+=restoran_pica;brojac_pica++;}
	else if(jelo1=='H'){cijena1+=restoran_hamburger;brojac_hamburger++;}
	else if(jelo1=='C'){cijena1+=restoran_cevapi;brojac_cevapi++;}
	if(jelo2=='P'){cijena1+=restoran_pica;brojac_pica++;}
	else if(jelo2=='H'){cijena1+=restoran_hamburger;brojac_hamburger++;}
	else if(jelo2=='C'){cijena1+=restoran_cevapi;brojac_cevapi++;}
	if(jelo3=='P'){cijena1+=restoran_pica;brojac_pica++;}
	else if(jelo3=='H'){cijena1+=restoran_hamburger;brojac_hamburger++;}
	else if(jelo3=='C'){cijena1+=restoran_cevapi;brojac_cevapi++;}
	
	if(jelo1=='P') cijena2+=trovac_pica;
	else if(jelo1=='H') cijena2+=trovac_hamburger;
	else if(jelo1=='C') cijena2+=trovac_cevapi;
	if(jelo2=='P') cijena2+=trovac_pica;
	else if(jelo2=='H') cijena2+=trovac_hamburger;
	else if(jelo2=='C') cijena2+=trovac_cevapi;
	if(jelo3=='P') cijena2+=trovac_pica;
	else if(jelo3=='H') cijena2+=trovac_hamburger;
	else if(jelo3=='C') cijena2+=trovac_cevapi;
	
	if(jelo1=='P') cijena3+=bistro_pica;
	else if(jelo1=='H') cijena3+=bistro_hamburger;
	else if(jelo1=='C') cijena3+=bistro_cevapi;
	if(jelo2=='P') cijena3+=bistro_pica;
	else if(jelo2=='H') cijena3+=bistro_hamburger;
	else if(jelo2=='C') cijena3+=bistro_cevapi;
	if(jelo3=='P') cijena3+=bistro_pica;
	else if(jelo3=='H') cijena3+=bistro_hamburger;
	else if(jelo3=='C') cijena3+=bistro_cevapi;
	
	cijenasapopustom=cijena1;
	
	max=brojac_cevapi*restoran_cevapi;
	if(brojac_hamburger*restoran_hamburger>max) max=brojac_hamburger*restoran_hamburger;
	if(brojac_pica*restoran_pica>max) max=brojac_pica*restoran_pica;
	
	
	
	cijenasapopustom=cijenasapopustom-max;
	cijenasapopustom+=(max-max*0.1);
	
	if(cijena1<=cijena2 && cijena1<=cijena3){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena1);
	}
	else if(cijena2<=cijena1 && cijena2<=cijena3){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);
		if(cijenasapopustom<cijena2)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijenasapopustom);
	}
	else{
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		if(cijenasapopustom<cijena3)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM). ",cijenasapopustom);
	}
	
	return 0;
}
