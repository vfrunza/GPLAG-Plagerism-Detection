#include <stdio.h>

int main()
{
	double P_restoran=6.80, P_fastfood=8.00, P_bistro=5.30, H_restoran=3.30, H_fastfood=3.00, H_bistro=5.00, C_restoran=5.00, C_fastfood=3.90, C_bistro=6.00;
	double restoran, fastfood, bistro, restoran_sa_popustom, P_sa_popustom, H_sa_popustom, C_sa_popustom;
	char tarik, bojan, mirza, novi_red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);

	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	P_sa_popustom=P_restoran; H_sa_popustom=H_restoran; C_sa_popustom=C_restoran; /* postavljamo cijene na pocetne jer ne znamo sta ce biti snizeno */
	
	if( tarik == 'P' || bojan == 'P' || mirza == 'P' ){P_sa_popustom=P_restoran-(P_restoran*0.1);}
	else if( tarik == 'C' || bojan == 'C' || mirza == 'C' ){C_sa_popustom=C_restoran-(C_restoran*0.1);}
	else{H_sa_popustom=H_restoran-(H_restoran*0.1);}
	
	if ( tarik == 'P' ){restoran = P_restoran; fastfood = P_fastfood; bistro = P_bistro; restoran_sa_popustom = P_sa_popustom; }
	else if ( tarik == 'H' ){restoran = H_restoran; fastfood = H_fastfood; bistro = H_bistro; restoran_sa_popustom = H_sa_popustom; }
	else if ( tarik == 'C' ){restoran = C_restoran; fastfood = C_fastfood; bistro = C_bistro; restoran_sa_popustom = C_sa_popustom; }
	
	if ( bojan == 'P'){restoran+= P_restoran; fastfood+= P_fastfood; bistro+= P_bistro; restoran_sa_popustom+= P_sa_popustom; }
	else if ( bojan == 'H'){restoran+= H_restoran; fastfood+= H_fastfood; bistro+= H_bistro; restoran_sa_popustom+= H_sa_popustom; }
	else if ( bojan == 'C'){restoran+= C_restoran; fastfood+= C_fastfood; bistro+= C_bistro; restoran_sa_popustom+= C_sa_popustom; }
	
	if ( mirza == 'P'){restoran+= P_restoran; fastfood+= P_fastfood; bistro+= P_bistro; restoran_sa_popustom+= P_sa_popustom; }
	else if ( mirza == 'H'){restoran+= H_restoran; fastfood+= H_fastfood; bistro+= H_bistro; restoran_sa_popustom+= H_sa_popustom; }
	else if ( mirza == 'C'){restoran+= C_restoran; fastfood+= C_fastfood; bistro+=C_bistro; restoran_sa_popustom+=C_sa_popustom; }
	
if(restoran<fastfood && fastfood<bistro)
{
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).", restoran);
}

if(fastfood<restoran && fastfood<bistro)
{
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", fastfood);
	
	if(restoran_sa_popustom<fastfood)
{
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", restoran_sa_popustom);
}
}

if (bistro<restoran && bistro<fastfood)
{
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", bistro);
	if(restoran_sa_popustom<bistro)
{
	printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", restoran_sa_popustom);
}
}

return 0;
}
