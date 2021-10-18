#include <stdio.h>

int main() {
	char tarik,bojan,mirza,novired;
	float cr=0,cf=0,cb=0;
	printf ("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan),
	scanf("%c",&novired),
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novired);
	
	

	
	if(tarik=='P'){
		cr=cr+6.8;
		cf=cf+8;
		cb=cb+5.3;
	}
	else if(tarik=='H'){
		cr=cr+3.3;
		cf=cf+3;
		cb=cb+5;
	}
    else{
		cr=cr+5;
		cf=cf+3.9;
		cb=cb+6;
	}
	if(bojan=='P'){
		cr=cr+6.8;
		cf=cf+8;
		cb=cb+5.3;
	}
	else if(bojan=='H'){
		cr=cr+3.3;
		cf=cf+3;
		cb=cb+5;
	
	}
	else{
		cr=cr+5;
		cf=cf+3.9;
		cb=cb+6;
		
	}
	if(mirza=='P'){
		cr=cr+6.8;
		cf=cf+8;
		cb=cb+5.3;
	}
	else if(mirza=='H'){
		cr=cr+3.3;
		cf=cf+3;
		cb=cb+5;
	}
	else{
		cr=cr+5;
		cf=cf+3.9;
		cb=cb+6;
	}
	

	
	
	float nj;
	if(cr<cf && cr<cb){
		nj=cr;
	}
	else if(cf<cr && cf<cb){
		nj=cf;
	}
	else{
		nj=cb;
	}
	if (nj==cr){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%0.2f KM).",nj);
	}
	if(nj==cf){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%0.2f KM).",nj);
	}
	if(nj==cb){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%0.2f KM).",nj);
	}
	printf("\n");
		float popust;
	if(tarik=='P' || bojan=='P' || mirza=='P'){
		popust=(10*6.8)/100;
		
	}
	if((tarik=='P' && bojan=='P')||(tarik=='P' && mirza=='P')|| (bojan=='P' && mirza=='P')){
		popust=(10*2*6.8)/100;
		
	}
	if(tarik=='P' && bojan=='P' && mirza=='P'){
		popust=(10*3*6.8)/100;
		
	}

	if(tarik=='H' || bojan=='H' || mirza=='H'){
		popust=(10*3.3)/100;
		
	}
	if((tarik=='H' && bojan=='H')|| (tarik=='H' && mirza=='H')|| (bojan=='H' && mirza=='H')){
		popust=(10*2*3.3)/100;
		
	}
	if(tarik=='H' && bojan=='H' && mirza=='H'){
		popust=(10*3*3.3)/100;
		
	}
    
    
	
	if(tarik=='C' || bojan=='C' || mirza=='C'){
		popust=(10*5)/100;
		
	}
	if((tarik=='C' && bojan=='C')|| (tarik=='C' && mirza=='C')|| (bojan=='C' && mirza=='C')) {
		popust=(10*2*5)/100;
		
	}
	if(tarik=='C' && bojan=='C' && mirza=='C'){
		popust=(10*3*5)/100;
		
	}
	
	
	if((nj!=cr)&&(cr-popust<nj)) {
		printf("Sa popustom bi Restoran bio jeftiniji (%0.2f KM).",cr-popust);
		
	}
	return 0;
}
