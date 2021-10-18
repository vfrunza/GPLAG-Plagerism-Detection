#include <stdio.h>

#define PR 6.8
#define HR 3.3
#define CR 5.0
#define PF 8.0
#define HF 3.0
#define CF 3.9
#define PB 5.3
#define HB 5.0
#define CB 6.0

int main() {
	/*printf("Zadaća 1, Zadatak 1");*/
	char t,b,m,nr;
	float csp;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&nr);
	/*p,p,p*/
	if(t=='P' && b=='P' && m=='P'){
		if(PR*3<PR*3 && PR*3<PB*3) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",34,34,PR*3);
		else{
			csp=PR*0.9*3;
			if(PF*3<PB*3){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,PF*3.);
				if(csp<PF*3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else{
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,PB*3);
				if(csp<PB*3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
		}
	}
	/*h,h,h*/
	else if(t=='H' && b=='H' && m=='H'){
		if(HR*3<HF*3 && HR*3<HB*3) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",34,34,HR*3);
		else{
			csp=HR*0.9*3;
			if(HF*3<HB*3){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,HF*3);
				if(csp<HR*3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else{ 
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,HB*3);
				if(csp<HB*3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
		}
	}
	/*c,c,c*/
	else if(t=='C' && b=='C' && m=='C'){
		if(CR*3<CF*3 && CR*3<CB*3) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",34,34,CR*3);
		else{
			csp=CR*3*0.9;
			if(CF*3<CB*3){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,CF*3);
				if(csp<CF*3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else{
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,CB*3);
				if(csp<CB*3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
		}
	}
	/*p,h,h*/
	else if((t=='P' && b=='H' && m=='H') || (t=='H' && b=='P' && m=='H') || (t=='H' && b=='H' && m=='P')){
		if((PR+HR*2)<(PB+HB*2)  && (PR+HR*2)<(PB+HB*2)) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",34,34,PR+HR*2);
		else{
			csp=PR*0.9+2*HR;
			if((PF+HF*2)<(PB+HB*2)){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,PF+HF*2);
				if(csp<(PF+HF*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else{
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,PB+HB*2);
				if(csp<(PB+HB*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			} 
		}
	}
	/*p,c,c*/
	else if((t=='P' && b=='C' && m=='C') || (t=='C' && b=='P' && m=='C') || (t=='C' && b=='C' && m=='P')){
		if((PR+CR*2)<(PF+CF*2) && (PR+CR*2)<(PB+CB*2)) printf("Najjeftiniji je Restoran %cKod konja i konusara%c (%.2f KM).\n",34,34,PR+CR*2);
		else{
			csp=PR+CR*2*0.9;
			if((PF+CF*2)<(PB+CB*2)){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,PF+CF*2);
				if(csp<(PF+CF*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else{
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,PB+CB*2);
				if(csp<(PB+CB*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
		}
	}
	/*h,p,p*/
	else if((t=='H' && b=='P' && m=='P')||(t=='P' && b=='H' && m=='P')||(t=='P' && b=='P' && m=='H')){
		if((HR+PR*2)<(HF+PF*2)&&(HR+PR*2)<(HB+PB*2)) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n,",34,34,HR+PR*2);
		else{
			csp=PR*2*0.9+HR;
			if((HF+PF*2)<(HB+PB*2)){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,HF+PF*2);
				if(csp<(HF+PF*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2F KM).\n",34,34,csp);
			}
			else printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,HB+PB*2);
			if(csp<(HB+PB*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
		}
	}
	/*h,c,c*/
	if((t=='H' && b=='C' && m=='C')||(t=='C' && b=='H' && m=='C')||(t=='C' && b=='C' && m=='H')){
		if((HR+CR*2)<(HF+CF*2) && (HR+CR*2)<(HB+CB*2)) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",34,34,HR+CR*2);
		else{
			csp=HR+CR*2*0.9;
			if((HF+CF*2)<(HB+CB*2)){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,HF+CF*2);
				if(csp<(HF+CF*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else{
				printf("Najjeftiniji ja Bistro %cLorelei%c (%.2f KM).\n",34,34,HB+CB*2);
				if(csp<(HB+CB*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
		}
	}
	/*c,h,h*/
	if((t=='C'&& b=='H' && m=='H')||(t=='H' && b=='C' && m=='H')||(t=='H' && b=='H' && m=='C')){
		if((CR+HR*2)<(CF+HF*2) && (CR+HR*2)<(CB+HB*2)) printf("Najjeftiniji je Restoran %cKod kona i konjusara (%.2f KM).\n",34,34,CR+HR*2);
		else{
			csp=CR*HR*2*0.9;
			if((CF+HF*2)<(CB+HB*2)){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,CF+HF*2);
				if(csp<(CF+HF*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
				}
				else{
					printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,CB+HB*2);
					if(csp<(CB+HB*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
				}
		}
	}
	/*c,p,p*/
	if((t=='C' && b=='P' && m=='P')||(t=='P' && b=='C' && m=='P') || (t=='P' && b=='P' && m=='C')){
		if((CR+PR*2)<(CF+PF*2) && (CR+PR*2)<(CB+PB*2)) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",34,34,CR+PR*2);
		else{
			csp=CR+PR*2*0.9;
			if((CF+PF*2)<(CB+PB*2)){ 
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,CF+PF*2);
				if(csp<(CF+PF*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,CB+PB*2);
			if(csp<(CB+PB*2)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
		}
	}
	/*p,h,c*/
	if((t=='P'&&b=='C'&&m=='H')||(t=='P'&&b=='H'&& m=='C')||(t=='H'&&b=='P'&&m=='C')||(t=='H'&&b=='C'&&m=='P')||(t=='C'&&b=='H'&&m=='P')||(t=='C'&&b=='P'&&m=='H')){
		if((PR+HR+CR)<(PF+HF+CF) && (PR+HR+CR)<(PB+HB+CB)) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n",34,34,PR+HR+CR);
		else{
			csp=PR*0.9+HR+CR;
			if((PF+HF+CF)<(PB+HB+CB)){
				printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n",34,34,PF+HF+CF);
				if(csp<(PF+HF+CF)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
			else{
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n",34,34,PB+HB+CB);
				if(csp<(PB+HB+CB)) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",csp);
			}
		}
	}
	return 0;
}
