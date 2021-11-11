#include <stdio.h>

int main() {
	
	char t,b,m,red;
	double restoran=0,fast=0,bistro=0,popust,br1=0,br2=0,br3=0,m_pica=0,m_hamburger=0,m_cevapi=0,ukupno=0,pica,hamburger,cevapi;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	
	if(t=='P'){	restoran+=6.80; fast+=8.0; bistro+=5.30; br1++;}
	if(t=='H'){ restoran+=3.30; fast+=3.0; bistro+=5.0;br2++;}
	if(t=='C'){ restoran+=5.0; fast+=3.90; bistro+=6.0;br3++;}
	
	if(b=='P'){	restoran+=6.80; fast+=8.0; bistro+=5.30;br1++;}
	if(b=='H'){ restoran+=3.30; fast+=3.0; bistro+=5.0;br2++;}
	if(b=='C'){ restoran+=5.0; fast+=3.90; bistro+=6.0;br3++;}
	
	if(m=='P'){	restoran+=6.80; fast+=8.0; bistro+=5.30;br1++;}
	if(m=='H'){ restoran+=3.30; fast+=3.0; bistro+=5.0;br2++;}
	if(m=='C'){ restoran+=5.0; fast+=3.90; bistro+=6.0;br3++;}
	
	m_pica=6.80*br1;
	m_hamburger=3.30*br2;
	m_cevapi=5*br3;
	pica=6.80;
	hamburger=3.30;
	cevapi=5.0;
	if(m_pica>m_hamburger && m_pica>m_cevapi){ popust=0.1*pica; pica-=popust; ukupno=pica*br1+hamburger*br2+cevapi*br3;  }
	if(m_hamburger>m_pica && m_hamburger>m_cevapi){popust=0.1*hamburger; hamburger-=popust;ukupno=pica*br1+hamburger*br2+cevapi*br3;}
	if(m_cevapi>m_pica && m_cevapi>m_hamburger){popust=0.1*cevapi; cevapi-=popust; ukupno=pica*br1+hamburger*br2+cevapi*br3;}
	
	if(restoran<fast && restoran<bistro){ printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",restoran); return 0;}
	if(fast<restoran && fast<bistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",fast);
	if(bistro<fast && bistro<restoran) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",bistro);
	if(ukupno<fast && ukupno<bistro) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",ukupno);
	return 0;
}
