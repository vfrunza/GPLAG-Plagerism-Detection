#include <stdio.h>

int main() {
	char a;
	char r;
	float zeko;
	float posto;
	int BRC=0,BRB=0,BRS=0,BRV=0,BRP=0;
	printf("Unesite vozila: ");
	
    do{
    	
		scanf("%c",&a);
		if(a=='c'|| a=='C') BRC++;
		if(a=='b'|| a=='B') BRB++;
		if(a=='s'|| a=='S') BRS++;
		if(a=='v'|| a=='V') BRV++;
		if(a=='p'|| a=='P') BRP++;
    
   	if(a!='K' && a!='k' && a!='C' && a!='c' && a!='B' && a!='b' && a!='S' && a!='s' && a!='V' && a!='v' && a!='P' && a!='p'){
		printf("Neispravan unos \n");
		scanf("%c",&a);
	}
			
			if(BRC>BRB && BRC>BRS && BRC>BRV && BRC>BRP)
			r='c';
			if(BRB>BRC && BRB>BRS && BRB>BRV && BRB>BRP)
			r='b';
			if(BRS>BRC && BRS>BRB && BRS>BRV && BRS>BRP)
			r='s';
			if(BRV>BRC && BRV>BRB && BRV>BRS && BRV>BRP)
			r='v';
			if(BRP>BRC && BRP>BRB && BRP>BRS && BRP>BRV)
			r='p';
			
			if(a!='K' && a!='k' && a!='C' && a!='c' && a!='B' && a!='b' && a!='S' && a!='s' && a!='V' && a!='v' && a!='P' && a!='p'){
		printf("Neispravan unos \n");
		scanf("%c",&a);
	}
		
	
}
	while(a!='K' && a!='k');
    	printf("Ukupno evidentirano %d vozila. \n",BRC+BRB+BRS+BRV+BRP);
	if(r=='c'){
		zeko=BRC;
	posto=((zeko/(BRC+BRB+BRS+BRV+BRP))*100);
	printf("Najpopularnija boja je crna (%.2f%%).",posto);}
	if(r=='b'){
		zeko=BRB;
				posto=((zeko/(BRC+BRB+BRS+BRV+BRP))*100);
	printf("Najpopularnija boja je bijela (%.2f%%).",posto);}
	if(r=='s'){
		zeko=BRS;
			posto=((zeko/(BRC+BRB+BRS+BRV+BRP))*100);	
	
	printf("Najpopularnija boja je siva (%.2f%%).",posto);}
	if(r=='v'){
		zeko=BRV;
			posto=((zeko/(BRC+BRB+BRS+BRV+BRP))*100);
	printf("Najpopularnija boja je crvena (%.2f%%).",posto);}
	if(r=='p'){
		zeko=BRP;
			posto=((zeko/(BRC+BRB+BRS+BRV+BRP))*100);
	printf("Najpopularnija boja je plava (%.2f%%).",posto);}
    
    
		
	return 0;
}
