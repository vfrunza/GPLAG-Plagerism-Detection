#include <stdio.h>

int main() {
	char x;
	int U,sc=0,sb=0,ss=0,sv=0,sp=0;
	float puc,pub,pus,puv,pup;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&x);
		
	 
		if(x=='C' || x=='c'){ 
			sc=sc+1;
		} 
	    
		if(x=='B'|| x=='b'){ 
			sb=sb+1;
			
		} 
		
		if(x=='S'|| x=='s'){
			ss=ss+1;
			
		} 
	
		if(x=='V' || x=='v'){
		    sv=sv+1;
			
			
		}
		
		if(x=='P'|| x=='p'){
			sp=sp+1;
			
		} 
		if(x!='C' && x!='c' && x!='B'&& x!='b' && x!='S' && x!='s' && x!='V' && x!='v' && x!='P' && x!='p' && x!='K' && x!='k'){
		printf("Neispravan unos\n"); 
		}
	}
	while(x!='K'&& x!='k');
		U=sc+sb+ss+sv+sp;

	
	printf("Ukupno evidentirano %d vozila.",U);
	if (U==0){
		printf("\nNajpopularnija boja je crna (0.00%%).");
	}
	else{
			 
	 puc=(float)(sc*100)/U ;
	 pub=(float)(sb*100)/U ;
	 pus=(float)(ss*100)/U ;
	 puv=(float)(sv*100)/U ;
	 pup=(float)(sp*100)/U ;
	 
		if(puc>=pub && puc>=pus && puc>=puv && puc>=pup){
	    	printf("\nNajpopularnija boja je crna (%.2f%%).",puc);
		}
		else if(pub>=pus && pub>puc && pub>=puv && pub>=pup){
	    	printf("\nNajpopularnija boja je bijela (%.2f%%).",pub);
		}
		else if(pus>=puv && pus>puc && pus>pub && pus>=pup){
			printf("\nNajpopularnija boja je siva (%.2f%%).",pus);
		}
		else if(puv>=pup && puv>puc && puv>pus && puv>pub){
			printf("\nNajpopularnija boja je crvena (%.2f%%).",puv);
		}
		else if(pup>puc && pup>pub && pup>pus && pup>puv){
			printf("\nNajpopularnija boja je plava (%.2f%%).",pup);
		}
	}
	
	return 0;
}
