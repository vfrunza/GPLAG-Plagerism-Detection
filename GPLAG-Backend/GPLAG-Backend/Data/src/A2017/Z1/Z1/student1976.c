/*#include <stdio.h>
#define EPSILON 0.01
#include <math.h>
int main() {
	char t,b,m,novi_red;
	float cijena1, cijena2, cijena3,min;
    float kp=6.8, kh=3.3, kc=5, tp=8, th=3, tc=3.90, lp=5.3, lh=5, lc=6;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &novi_red);
	if(t+b+m=='P'+'C'+'H') {
		cijena1=kp+kh+kc;
		cijena2=tp+th+tc;
		cijena3=lp+lh+lc;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=kp*0.9+kh+kc;
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
if(t+b+m=='H'+'H'+'H') {
		cijena1=kh+kh+kh;
		cijena2=th+th+th;
		cijena3=lh+lh+lh;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=3*(kh*0.9);
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
	if(t+b+m=='P'+'P'+'P') {
		cijena1=kp+kp+kp;
		cijena2=tp+tp+tp;
		cijena3=lp+lp+lp;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
	    if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=3*(kp*0.9);
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
		if(t+b+m=='C'+'C'+'C') {
		cijena1=kc+kc+kc;
		cijena2=tc+tc+tc;
		cijena3=lc+lc+lc;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=3*(kc*0.9);
		}
		if (cijena1-cijena2<EPSILON || cijena1-cijena3<EPSILON) {
			printf(" ");}else printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
	if(t+b+m=='H'+'H'+'C') {
		cijena1=kh+kh+kc;
		cijena2=th+th+tc;
		cijena3=lh+lh+lc;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=2*(kh*0.9)+kc;
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
	if(t+b+m=='P'+'P'+'C') {
		cijena1=kp+kp+kc;
		cijena2=tp+tp+tc;
		cijena3=lp+lp+lc;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=2*(kp*0.9)+kc;
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
	if(t+b+m=='C'+'C'+'H') {
		cijena1=kc+kc+kh;
		cijena2=tc+tc+th;
		cijena3=lc+lc+lh;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=2*(kc*0.9)+kh;
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
	if(t+b+m=='C'+'C'+'P') {
		cijena1=kc+kc+kp;
		cijena2=tc+tc+tp;
		cijena3=lc+lc+lp;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=2*(kc*0.9)+kp;
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
	if(t+b+m=='H'+'H'+'P') {
		cijena1=kh+kh+kp;
		cijena2=th+th+tp;
		cijena3=lh+lh+lp;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=kp*0.9+kh+kh;
		}
	if (cijena1-cijena2<EPSILON && cijena1-cijena3<EPSILON) {
			printf(" ");} else printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	
	}
	if(t+b+m=='P'+'P'+'H') {
		cijena1=kp+kp+kh;
		cijena2=tp+tp+th;
		cijena3=lp+lp+lh;
		if(cijena1<cijena2 && cijena1<cijena3) {
			min=cijena1; 
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).\n",cijena1);
			
		}
		if(cijena2<cijena1 && cijena2<cijena3) 
		{ 
			min=cijena2; 
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
		if(cijena3<cijena1 && cijena3<cijena2) {
			min=cijena3;
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
		
		}
		if(cijena1-min>EPSILON) 
		{
			cijena1=2*kp*0.9+kh;
		}
		if(cijena1<cijena2 && cijena1<cijena3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",cijena1);
	
	}
	return 0;
}
*/
#include <math.h>
#include <stdio.h>
#define EPSILON 0.001
int main(){
	int brojac_hamburger=0,brojac_pica=0,brojac_cevapi=0;
	char t,b,m,novi_red;
	float kp,kh,kc,tp,th,tc,lp,lh,lc,cijena1,cijena2,cijena3,min=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &novi_red);
	if(t=='H') brojac_hamburger++; else if(t=='P') brojac_pica++; else if(t=='C') brojac_cevapi++;
	if(b=='H') brojac_hamburger++; else if(b=='P') brojac_pica++; else if(b=='C') brojac_cevapi++;
	if(m=='H') brojac_hamburger++; else if(m=='P') brojac_pica++; else if(m=='C') brojac_cevapi++;
	kp=6.8; kh=3.3; kc=5.0;
	tp=8.0; th=3.0; tc=3.9;
	lp=5.3; lh=5.0; lc=6.0;
	cijena1=brojac_pica*kp+brojac_hamburger*kh+brojac_cevapi*kc;
	cijena2=brojac_pica*tp+brojac_hamburger*th+brojac_cevapi*tc;
	cijena3=brojac_pica*lp+brojac_hamburger*lh+brojac_cevapi*lc;
	if(cijena2<cijena1 && cijena2<cijena3){
	    min=cijena2;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);
	}
	if(cijena3<cijena1 && cijena3<cijena2){ 
		min=cijena3;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);
	}
	if(cijena1<cijena2 && cijena1<cijena3){
		min=cijena1;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena1);
	}
	if(cijena1-min>EPSILON) {{
		if(brojac_cevapi*kc>brojac_hamburger*kh && brojac_cevapi*kc>brojac_pica*kp) 
			cijena1=brojac_pica*kp+brojac_hamburger*kh+(0.9*brojac_cevapi*kc);
			else if(brojac_hamburger*kh>brojac_cevapi*kc && brojac_hamburger*kh>brojac_pica*kp)
				cijena1=brojac_pica*kp+(0.9*brojac_hamburger*kh)+brojac_cevapi*kc;
				else if(brojac_pica*kp>brojac_cevapi*kc && brojac_pica*kp>brojac_hamburger*kh)
					cijena1=(0.9*brojac_pica*kp)+brojac_hamburger*kh+brojac_cevapi*kc;
		}
	
    if(cijena1<cijena2 && cijena1<cijena3) 
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena1);
	}
	
	return 0;
	
}