#include <stdio.h>

int main() {
	char t,b,m,novi_red;
	float H1=3.30,P1=6.80,C1=5.00,H2=3.00,P2=8.00,C2=3.90,H3=5.00,P3=5.30,C3=6.00,ceh1=0,ceh2=0,ceh3=0,min,suma=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	if(t=='P')
	{
		ceh1+=P1;
		ceh2+=P2;
		ceh3+=P3;
	}
	else if(t=='H')
	{
		ceh1+=H1;
		ceh2+=H2;
		ceh3+=H3;
	}
	else if(t=='C')
	{
		ceh1+=C1;
		ceh2+=C2;
		ceh3+=C3;
	}
	if(b=='P')
	{
		ceh1+=P1;
		ceh2+=P2;
		ceh3+=P3;
	}
	else if(b=='H')
	{
		ceh1+=H1;
		ceh2+=H2;
		ceh3+=H3;
	}
	else if(b=='C')
	{
		ceh1+=C1;
		ceh2+=C2;
		ceh3+=C3;
	}
	if(m=='P')
	{
		ceh1+=P1;
		ceh2+=P2;
		ceh3+=P3;
	}
	else if(m=='H')
	{
		ceh1+=H1;
		ceh2+=H2;
		ceh3+=H3;
	}
	else if(m=='C')
	{
		ceh1+=C1;
		ceh2+=C2;
		ceh3+=C3;
	}
	min=ceh1;
	if (ceh2<min) {
		min=ceh2; printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
	}
	else if(ceh3<min)
	{
		min=ceh3; printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
	}
	else
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
	if(min!=ceh1)
	{
		
		if(t!=b && t!=m && b!=m) {suma=H1+P1+C1-P1*0.1; if(suma<ceh2) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",suma);}
			if(t=='H' && (t==b || t==m)  && (b=='P' || m=='P'))
		if(2*H2+P2>(2*H1+P1)-2*P1*0.1) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(2*H1+P1)-P1*0.1);
			
			if(t=='P' && (t==b || t==m)  && (b=='H' || m=='H'))
		if(2*P3+H3>(2*P1+H1)-2*P1*0.1) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(2*P1+H1)-2*P1*0.1);
			
			if(t=='P' && (t==b || t==m)  && (b=='C' || m=='C'))
		if(2*P3+C3>(2*P1+C1)-2*P1*0.1) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(2*P1+C1)-2*P1*0.1);
			
			if(t=='C' && (t==b || t==m)  && (b=='P' || m=='P'))
		if(2*C2+P2>(2*C1+P1)-2*C1*0.1) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(2*C1+P1)-2*C1*0.1);
			
			if(t=='C' && (t==b || t==m)  && (b=='H' || m=='H'))	
		if(2*C2+H2>(2*C1+H1)-2*C1*0.1) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(2*C1+H1)-2*C1*0.1);
			
			if(t=='H' && (t==b || t==m)  && (b=='C' || m=='C'))
		if(2*H2+C2>(2*H1+C1)-2*H1*0.1) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",(2*H1+C1)-2*H1*0.1);
	
		
	}
	return 0;
}
