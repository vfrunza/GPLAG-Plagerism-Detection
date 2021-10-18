#include <stdio.h>
#define RP 6.80
#define RH 3.30
#define RC 5.00
#define FP 8.00
#define FH 3.00
#define FC 3.90
#define BP 5.30
#define BH 5.00
#define BC 6.00

int main (){
	
	char tarik, bojan, mirza, novi_red;
	double restoran,fast_food,bistro,popust_restoran;
	double najjeftinije;
	int p,h,c;
	p=0;
	h=0;
	c=0;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &novi_red);
	
	if (tarik=='P') p++;
	else if (tarik=='H') h++;
	else if (tarik=='C') c++;
	
		if (bojan=='P') p++;
	else if (bojan=='H') h++;
	else if (bojan=='C') c++;
	
		if (mirza=='P') p++;
	else if (mirza=='H') h++;
	else if (tarik=='C') c++;
	
	if(p==3) {
		restoran=RP*3;
		fast_food=FP*3;
		bistro=BP*3;
		if (restoran<fast_food && restoran<bistro) {
			najjeftinije=restoran; printf ("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2lf KM).", najjeftinije ); }
		else if (bistro<restoran && bistro<fast_food){ najjeftinije=bistro;
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).", najjeftinije ); }
		else if (fast_food<bistro && fast_food<restoran) {
			najjeftinije=fast_food; printf ("Najjeftiniji je Fast-food \"Trovač\" (%.2lf KM).", najjeftinije ); }
	}
	
	if(h==3){
		restoran = RH*3;
		fast_food = FH*3;
		bistro = BH*3;
		popust_restoran=restoran-restoran*0.1;
		if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
}

if(c==3){
		restoran = RC*3;
		fast_food = FC*3;
		bistro = BC*3;
		popust_restoran=restoran-restoran*0.1;
		if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
}

if(p==2 && h==1){
	double popust1,popust2,popust_pizza,popust_hamburger;
	double bistro_p, restoran_p, fast_food_p;
	bistro_p=BP*2;
	restoran_p=RP*2;
	fast_food_p=FP*2;
	double bistro_h, restoran_h, fast_food_h;
	bistro_h=BH;
	restoran_h=RH;
	fast_food_h=FH;
    restoran=restoran_p+restoran_h;
    fast_food=fast_food_h+fast_food_p;
    bistro=bistro_h+bistro_p;
    popust_pizza=RP-RP*0.1;
    popust_hamburger=RH-RH*0.1;
    popust1=popust_pizza*2+RH;
    popust2=RP*2+popust_hamburger;
    if (popust1<popust2) popust_restoran=popust1;
    else if(popust2<popust1) popust_restoran=popust2;
    
    	if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
    
}
	
if (p==1 && h==1 && c==1){
	double ffp,ffh,ffc;
	double bp,bc,bh;
	double rh,rp,rc;
	ffp=FP;
	ffh=FH;
	ffc=FC;
	bp=BP;
	bc=BC;
	bh=BH;
	rh=RH;
	rc=RC;
	rp=RP;
	fast_food=ffp+ffh+ffc;
	bistro=bp+bc+bh;
	restoran=rh+rc+rp;
	double p1,p2,p3,pop_h,pop_c,pop_p;
	pop_p=rp-rp*0.1;
	pop_h=rh-rh*0.1;
	pop_c=rc-rc*0.1;
	p1=pop_p+rh+rc;
	p2=pop_h+rc+rp;
	p3=pop_c+rh+rp;
	if (p1<p2 && p1<p3) popust_restoran=p1;
	if (p2<p1 && p2<p3) popust_restoran=p2;
	if (p3<p2 && p3<p1) popust_restoran=p3;
		if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
}	

if(h==2 && p==1){
	double popust1,popust2,popust_pizza,popust_hamburger;
	double bistro_h, restoran_h, fast_food_h;
	bistro_h=BH*2;
	restoran_h=RH*2;
	fast_food_h=FH*2;
	double bistro_p, restoran_p, fast_food_p;
	bistro_p=BP;
	restoran_p=RP;
	fast_food_p=FP;
    restoran=restoran_p+restoran_h;
    fast_food=fast_food_h+fast_food_p;
    bistro=bistro_h+bistro_p;
    popust_hamburger=RH-RH*0.1;
    popust_pizza=RP-RP*0.1;
    popust1=popust_hamburger*2+RP;
    popust2=RH*2+popust_pizza;
    if (popust1<popust2) popust_restoran=popust1;
    else if(popust2<popust1) popust_restoran=popust2;
    
    	if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
    
}

if(c==2 && p==1){
	double popust1,popust2,popust_pizza,popust_cevapi;
	double bistro_c, restoran_c, fast_food_c;
	bistro_c=BC*2;
	restoran_c=RC*2;
	fast_food_c=FC*2;
	double bistro_p, restoran_p, fast_food_p;
	bistro_p=BP;
	restoran_p=RP;
	fast_food_p=FP;
    restoran=restoran_c+restoran_p;
    fast_food=fast_food_c+fast_food_p;
    bistro=bistro_c+bistro_p;
    popust_cevapi=RC-RC*0.1;
    popust_pizza=RP-RP*0.1;
    popust1=popust_cevapi*2+RP;
    popust2=RC*2+popust_pizza;
    if (popust1<popust2) popust_restoran=popust1;
    else if(popust2<popust1) popust_restoran=popust2;
    
    	if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
    
}

if(h==2 && c==1){
	double popust1,popust2,popust_cevap,popust_hamburger;
	double bistro_h, restoran_h, fast_food_h;
	bistro_h=BH*2;
	restoran_h=RH*2;
	fast_food_h=FH*2;
	double bistro_c, restoran_c, fast_food_c;
	bistro_c=BC;
	restoran_c=RC;
	fast_food_c=FC;
    restoran=restoran_h+restoran_c;
    fast_food=fast_food_h+fast_food_c;
    bistro=bistro_h+bistro_c;
    popust_hamburger=RH-RH*0.1;
    popust_cevap=RC-RC*0.1;
    popust1=popust_hamburger*2+RC;
    popust2=RH*2+popust_cevap;
    if (popust1<popust2) popust_restoran=popust1;
    else if(popust2<popust1) popust_restoran=popust2;
    
    	if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
    
}

if(c==1 && p==2){
	double popust1,popust2,popust_cev,popust_piz;
	double bistro_p, restoran_p, fast_food_p;
	bistro_p=BP*2;
	restoran_p=RP*2;
	fast_food_p=FP*2;
	double bistro_c, restoran_c, fast_food_c;
	bistro_c=BC;
	restoran_c=RC;
	fast_food_c=FC;
    restoran=restoran_c+restoran_p;
    fast_food=fast_food_c+fast_food_p;
    bistro=bistro_c+bistro_p;
    
    
    
    	if (restoran < fast_food && restoran < bistro){
			najjeftinije=restoran;
			printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).", najjeftinije ); 
			
		}
		
		else if (bistro < restoran && bistro < fast_food){
			najjeftinije = bistro;
				printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", najjeftinije );
				if (popust_restoran < bistro) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
		}
		else if (fast_food < bistro && fast_food < restoran){
			najjeftinije = fast_food;
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", najjeftinije ); 
			if (popust_restoran < fast_food) {
					printf ("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", popust_restoran);
				}
	}
    
}
	return 0;
}