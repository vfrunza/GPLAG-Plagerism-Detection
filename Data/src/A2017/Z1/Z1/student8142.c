#include <stdio.h>

int main() {
	
	char Tarik, Bojan, Mirza,n_red;
	double c_rest=0, c_fast=0, c_bis=0;
	double r_kkkp=6.8,ff_kp=8,b_lp=5.3,r_kkkh=3.3,ff_kh=3,b_lh=5,r_kkkc=5,ff_kc=3.9,b_lc=6;
	int brHam=0,brPizz=0,brCev=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &Tarik);
	scanf("%c", &n_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &n_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &n_red);
	
	if(Tarik=='H') brHam++;
	else if(Tarik=='P') brPizz++;
	else if(Tarik=='C') brCev++;
	
	if(Bojan=='H') brHam++;
	else if(Bojan=='P') brPizz++;
	else if(Bojan=='C') brCev++;
	
	if(Mirza=='H') brHam++;
	else if(Mirza=='P') brPizz++;
	else if(Mirza=='C') brCev++;
	
	c_rest=r_kkkh*brHam+r_kkkp*brPizz+r_kkkc*brCev;
	c_fast=ff_kh*brHam+ff_kp*brPizz+ff_kc*brCev;
	c_bis=b_lh*brHam+b_lp*brPizz+b_lc*brCev;
	
	if(c_rest<c_fast && c_rest<c_bis) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",c_rest);
	else
	{
	    if(c_fast<c_rest && c_fast<c_bis) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",c_fast);
	    else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",c_bis);
	    
	    if(brHam>brPizz && brHam>brCev)
	        r_kkkh*=0.9;
	    else if(brCev>brHam && brCev>brHam)
	        r_kkkc*=0.9;
	    else
	        r_kkkp*=0.9;
	
	c_rest=brHam*r_kkkh+brPizz*r_kkkp+brCev*r_kkkc;
	
	if(c_rest<c_fast && c_rest<c_bis) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",c_rest);
	
	}
	
	
	
	return 0;
}
