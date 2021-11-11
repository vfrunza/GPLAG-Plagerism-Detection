#include <stdio.h>
#include <math.h>
#define P1 6.80
#define H1 3.30
#define C1 5
#define P2 8
#define H2 3
#define C2 3.90
#define P3 5.30
#define H3 5
#define C3 6
#define e 0.0001

int main() {
	
	/*Ulaz*/
	
	char t, b, m;
	float c1, c2, c3, c, ch, cp, cc;
	printf("Unesite jelo za Tarika: ");
	scanf(" %c", &t);
	printf("Unesite jelo za Bojana: ");
	scanf(" %c", &b);
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c", &m);
	
	/*Pocela sam komplikovati..*/
	
	if (t=='H' && b=='H' && m=='H'){
	c1=3*H1;
	c2=3*H2;
	c3=3*H3;
	ch=c1-3*((1./10)*H1);
	cp=100;
	cc=100;
	}
	else{ 
		if(t=='P' && b=='P' && m=='P'){
		c1=3*P1;
		c2=3*P2;
		c3=3*P3;
		cp=c1-3*((1./10)*P1);
		ch=100;
		cc=100;
		}
		else{
			if(t=='C' && b=='C' && m=='C'){
			c1=3*C1;
			c2=3*C2;
			c3=3*C3;
			cc=c1-3*((1./10)*C1);
			cp=100;
			ch=100;
			}
		}}
		
		if((t=='H' && b=='H' && m=='P') || (t=='H' && b=='P' && m=='H') || (t=='P' && b=='H' && m=='H')){
		c1=2*H1+P1;
		c2=2*H2+P2;
		c3=2*H3+P3;
		ch=c1-2*((1./10)*H1);
		cp=c1-(1./10)*P1;
		cc=100;
		}
		else{ if((t=='H' && b=='H' && m=='C') || (t=='H' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='H')){
		c1=2*H1+C1;
		c2=2*H2+C2;
		c3=2*H2+C3;
		ch=c1-2*((1./10)*H1);
		cc=c1-(1./10)*C1;
		cp=100;
		}}
		
	    if((t=='P' && b=='H' && m=='P') || (t=='P' && b=='P' && m=='H') || (t=='H' && b=='P' && m=='P')){
		c1=2*P1+H1;
		c2=2*P2+H2;
		c3=2*P3+H3;
	    ch=c1-(1./10)*H1;
		cp=c1-2*((1./10)*P1);
		cc=100;
	    }
		else{ if((t=='P' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='P') || (t=='C' && b=='P' && m=='P')){
		c1=2*P1+C1;
		c2=2*P2+C2;
		c3=2*P3+C3;
		cp=c1-2*((1./10)*P1);
		cc=c1-(1./10)*C1;
		ch=100;
		}}
		
	    if((t=='C' && b=='H' && m=='C') || (t=='C' && b=='C' && m=='H') || (t=='H' && b=='C' && m=='C')){
		c1=2*C1+H1;
		c2=2*C2+H2;
		c3=2*C3+H3;
	    ch=c1-(1./10)*H1;
	    cc=c1-2*((1./10)*C1);
	    cp=100;
	    }
		else{ if((t=='C' && b=='P' && m=='C') || (t=='P' && b=='C' && m=='C') || (t=='C' && b=='C' && m=='P')){
		c1=2*C1+P1;
		c2=2*C2+P2;
		c3=2*C3+P3;
		cp=c1-(1./10)*P1;
		cc=c1-2*((1./10)*C1);
		ch=100;
		}}
		
		if((t=='H' && b=='P' && m=='C') || (t=='H' && b=='C' && m=='P') || (t=='P' && b=='H' && m=='C') || (t=='P' && b=='C' && m=='H') || (t=='C' && b=='H' && m=='P') || (t=='C' && b=='P' && m=='H')){
		c1=H1+P1+C1;
		c2=H2+P2+C2;
		c3=H3+P3+C3;
		ch=c1-(1./10)*H1;
		cp=c1-(1./10)*P1;
		cc=c1-(1./10)*C1;	
		}
		
		/*Necu jos puno komplikovati :)*/
		
		c=0;
		
		if(c1>c2 && c1>c3 && c2>c3 && !(fabs(c1-c2)<e) && !(fabs(c1-c3)<e) && !(fabs(c2-c3)<e)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", c3);
		c=c3;}
		else{
			if(c1>c2 && c1>c3 && c3>c2 && !(fabs(c1-c2)<e) && !(fabs(c1-c3)<e) && !(fabs(c2-c3)<e)){
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", c2);
			c=c2;}}
	
	    if(c>ch && cc>ch && cp>ch && !(fabs(c-ch)<e) && !(fabs(cc-ch)<e) && !(fabs(cp-ch)<e)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ch);
		return 1;}
		if(c>cp && ch>cp && cc>cp && !(fabs(c-cp)<e) && !(fabs(ch-cp)<e) && !(fabs(cc-cp)<e)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cp);
		return 1;}
	    if(c>cc && ch>cc && cp>cc && !(fabs(c-cc)<e) && !(fabs(ch-cc)<e) && !(fabs(cp-cc)<e)){
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cc);
		return 1;}
		
		if(c2>c1 && c2>c3 && c1>c3 && !(fabs(c1-c2)<e) && !(fabs(c1-c3)<e) && !(fabs(c2-c3)<e)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", c3);
		c=c3;}
		else{
			if(c2>c1 && c2>c3 && c3>c1 && !(fabs(c1-c2)<e) && !(fabs(c1-c3)<e) && !(fabs(c2-c3)<e))
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", c1);}
			
	   	if(c>ch && cc>ch && cp>ch && !(fabs(c-ch)<e) && !(fabs(cc-ch)<e) && !(fabs(cp-ch)<e)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ch);
		return 1;}
		if(c>cp && ch>cp && cc>cp && !(fabs(c-cp)<e) && !(fabs(ch-cp)<e) && !(fabs(cc-cp)<e)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cp);
		return 1;}
	    if(c>cc && ch>cc && cp>cc && !(fabs(c-cc)<e) && !(fabs(ch-cc)<e) && !(fabs(cp-cc)<e)){
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cc);
		return 1;}
		
		if(c3>c2 && c3>c1 && c1>c2 && !(fabs(c1-c2)<e) && !(fabs(c1-c3)<e) && !(fabs(c2-c3)<e)){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", c2);
		c=c2;}
		else{
			if(c3>c2 && c3>c1 && c2>c1 && !(fabs(c1-c2)<e) && !(fabs(c1-c3)<e) && !(fabs(c2-c3)<e)){
			printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", c1);
			}}
			
		if(c>ch && cc>ch && cp>ch && !(fabs(c-ch)<e) && !(fabs(cc-ch)<e) && !(fabs(cp-ch)<e)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ch);
		return 1;}
		if(c>cp && ch>cp && cc>cp && !(fabs(c-cp)<e) && !(fabs(ch-cp)<e) && !(fabs(cc-cp)<e)){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cp);
		return 1;}
	    if(c>cc && ch>cc && cp>cc && !(fabs(c-cc)<e) && !(fabs(ch-cc)<e) && !(fabs(cp-cc)<e)){
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", cc);
		return 1;}
		return 0;
		}
	
				
		
		
		
		
		
		
		
		
		
		
		
		