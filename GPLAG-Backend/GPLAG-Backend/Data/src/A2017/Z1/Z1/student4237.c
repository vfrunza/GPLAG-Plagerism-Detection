#include <stdio.h>
#include <math.h>
#define PK 6.80
#define PT 8.00
#define PL 5.30
#define HK 3.30
#define HT 3.00
#define HL 5.00
#define CK 5.00
#define CT 3.90
#define CL 6.00

int main() {
	
   int h=0,p=0,c=0;
   float a1=0,a2=0,a3=0,b1=0,b2=0,b3=0,c1=0,c2=0,c3=0,d1=0,d2=0,d3=0,e1=0,e2=0,e3=0,f1=0,f2=0,f3=0,g1=0,g2=0,g3=0,h1=0,h2=0,h3=0,i1=0,i2=0,i3=0,j1=0,j2=0,j3=0;
   float PKP,HKP,CKP,ap=0,bp=0,cp=0,dp=0,ep=0,hp=0,gp=0,fp=0,ip=0,jp=0;
   char bojan, tarik, mirza, novi_red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	
	if(tarik=='H'){
		h++;
	}
	else if(tarik=='P') {
		p++;
	}
	else {
		c++;
	}
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	
	if(bojan=='H'){
		h++;
	}
	else if(bojan=='P') {
		p++;
	}
	else {
		c++;
	}
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	
	if(mirza=='H'){
		h++;
	}
	else if(mirza=='P') {
		p++;
	}
	else {
		c++;
	}

	if(p==3) {
		a1=3*PK;
		a2=3*PT;
		a3=3*PL;
	}
	else if(c==3) {
		b1=3*CK;
		b2=3*CT;
		b3=3*CL;
	}
	else if(h==3) {
		c1=3*HK;
		c2=3*HT;
		c3=3*HL;
	}
	else if(h==1 && c==2) {
		d1=2*CK+HK;
		d2=2*CT+HT;
		d3=2*CL+HL;	
	}
	else if(p==1 && c==2) {
		e1=2*CK+PK;
		e2=2*CT+PT;
		e3=2*CL+PL;
	}
	else if(p==1 && h==2) {
		f1=2*HK+PK;
		f2=2*HT+PT;
		f3=2*HL+PL;
	}
	else if(p==1 && h==1 && c==1) {
		g1=CK+HK+PK;
		g2=CT+HT+PT;
		g3=CL+HL+PL;
	}
	else if(p==2 && h==1) {
		h1=2*PK+HK;
		h2=2*PT+HT;
		h3=2*PL+HL;
	}
	else if(p==2 && c==1) {
		i1=2*PK+CK;
		i2=2*PT+CT;
		i3=2*PL+CL;
	}
	else if(h==2 && c==1) {
		j1=2*HK+CK;
		j2=2*HT+CT;
		j3=2*HL+CL;
	}
	
	PKP=PK-((PK*10)/100);
	HKP=HK-((HK*10)/100);
	CKP=CK-((CK*10)/100);
	
	ap=3*PKP;
	bp=3*CKP;
	cp=3*HKP;
	dp=2*CKP+HK;
	ep=2*CKP+PK;
	fp=2*HKP+PK;
	hp=2*PKP+HK;
	gp=PKP+HK+CK;
	ip=2*PKP+CK;
	jp=2*HKP+CK;
	
	if(a1<a2 && a1<a3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",a1);
	}
		else if(a2<a1 && a2<a3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",a2); 	
		if(ap<a2) {
			printf("\nSa popustom bi bio jeftiniji: %.2f",ap);
		}
	}
	    else if(a3<a2 && a3<a1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",a3);
			if(ap<a3) {
			printf("\nSa popustom bi bio jeftiniji: %.2f",ap);
		}
	}
	 
	if(b1<b2 && b1<b3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM.",b1);
	}
		else if(b2<b1 && b2<b3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",b2);
			if(bp<b2) {
			printf("\nSa popustom bi bio jeftiniji: %.2f",bp);
		}
	}
	    else if(b3<b2 && b3<b1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",b3);
			if(bp<b3) {
			printf("\nSa popustom bi bio jeftiniji: %.2f",bp);
		}
	}
	
	if(c1<c2 && c1<c3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",c1);
	}
		else if(c2<c1 && c2<c3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",c2);
	
		if(cp<c2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cp);
		}
	}
	    else if(c3<c2 && c3<c1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",c3);
		if(cp<c3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cp);
		}
	}
	
	if(d1<d2 && d1<d3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",d1);
	}
		else if(d2<d1 && d2<d3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",d2);
			if(dp<d2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",dp);
		}
	}
	    else if(d3<d2 && d3<d1) {
		printf("Najjeftiniji je Bistro\"Lorelei\" (%.2f KM).",d3);
			if(dp<d3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",dp);
		}
	}
	
	if(e1<e2 && e1<e3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",e1);
	}
		else if(e2<e1 && e2<e3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",e2);
			if(ep<e2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ep);
		}
	}
	    else if(e3<e2 && e3<e1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",e3);
			if(ep<e3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ep);
		}
	}
	
	if(f1<f2 && f1<f3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",f1);
	}
		else if(f2<f1 && f2<f3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",f2);
		if(fp<f2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",fp);
		}
	}
	    else if(f3<f2 && f3<f1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",f3);
		if(fp<f3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",fp);
		}
	}
	
	if(g1<g2 && g1<g3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",g1);
	}
		else if(g2<g1 && g2<g3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",g2);
    	if(gp<g2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",gp);
		}
	}
	    else if(g3<g2 && g3<g1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",g3);
		if(gp<g3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",gp);
		}
	}
	
	if(h1<h2 && h1<h3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",h1);
	}
		else if(h2<h1 && h2<h3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",h2);
			if(hp<h2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",hp);
		}
	}
	    else if(h3<h2 && h3<h1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",h3);
			if(hp<h3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",hp);
		}
	}
	
	if(i1<i2 && i1<i3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",i1);
	}
		else if(i2<i1 && i2<i3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",i2);
			if(ip<i2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ip);
		}
	}
	    else if(i3<i2 && i3<i1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",i3);
			if(ip<i3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",ip);
		}
	}
	
	if(j1<j2 && j1<j3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",j1);
	}
		else if(j2<j1 && j2<j3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",j2);
		if(jp<j2) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",jp);
		}
	}
	    else if(j3<j2 && j3<j1) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",j3);
		if(jp<j3) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",jp);
		}
	}
	
	return 0;
}
