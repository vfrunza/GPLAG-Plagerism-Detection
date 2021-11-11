#include <stdio.h>
#include <math.h>

int main() 
{
	
double kkk=0, t=0, l=0, kkk_s_popustom=0, max=0, kkkp=0, kkkh=0, kkkc=0;
char tarik, bojan, mirza, novi_red, brojacP=0, brojacH=0, brojacC=0;

/*********************************************/

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
/*********************************************/

if (tarik=='P')
{ brojacP=brojacP+1; }

if (tarik=='H')
{ brojacH=brojacH+1; }

if (tarik=='C')
{ brojacC=brojacC+1; }

/*********************************************/

if (bojan=='P')
{ brojacP=brojacP+1; }

if (bojan=='H')
{ brojacH=brojacH+1; }

if (bojan=='C')
{ brojacC=brojacC+1; }

/*********************************************/

if (mirza=='P')
{ brojacP=brojacP+1; }

if (mirza=='H')
{ brojacH=brojacH+1; }

if (mirza=='C')
{ brojacC=brojacC+1; }

/*********************************************/

kkk=kkk+brojacP*6.80+brojacH*3.30+brojacC*5.00;
t=t+brojacP*8.00+brojacH*3.00+brojacC*3.90;
l=l+brojacP*5.30+brojacH*5.00+brojacC*6.00;

/*********************************************/

if ((kkk<t)&&(kkk<l))
{
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", kkk);
}

/*********************************************/

if ((t<kkk)&&(t<l))
{
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", t);
}

/*********************************************/

if ((l<kkk)&&(l<t))
{
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", l);
}

/*********************************************/

kkkp=brojacP*6.80;
kkkh=brojacH*3.30;
kkkc=brojacC*5.00;

/*********************************************/

if ((kkkp>kkkh)&&(kkkp>kkkc))
{ max=kkkp; }

if ((kkkc>kkkh)&&(kkkc>kkkp))
{ max=kkkc; }

if ((kkkh>kkkp)&&(kkkh>kkkc))
{ max=kkkh; }

/*********************************************/

kkk_s_popustom=kkk-(max*10)/100;

/*********************************************/

if ((kkk>t)||(kkk>l))
{
	if ((fabs(kkk_s_popustom-kkk)>0.01)||(fabs(kkk_s_popustom-t)>0.01)||(fabs(kkk_s_popustom-l)>0.01))
	{
	if ((kkk_s_popustom<kkk)&&((kkk_s_popustom)<t)&&(kkk_s_popustom<l))
	{
		printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk_s_popustom);
	}
	}
}
return 0;
}