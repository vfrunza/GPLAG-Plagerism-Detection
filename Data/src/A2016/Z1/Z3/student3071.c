#include <stdio.h>

int main() {
	char a; int brojac=0,cBrojac=0,bBrojac=0,sBrojac=0,vBrojac=0,pBrojac=0;
	int priBrojacC=0,priBrojacB=0,priBrojacS=0,priBrojacV=0,priBrojacP=0;
		printf("Unesite vozila: ");

	for(;;){
		scanf("%c",&a);
		//printf("\na iznosi: %c",a);
		if(a==' '){
			printf ("Neispravan unos\n");
		} else if(a=='C'||a=='c'){
			brojac++;
			cBrojac++;
			if (priBrojacC==0){priBrojacC-=brojac;}
		} else if (a=='b'||a=='B'){
			brojac++;
			bBrojac++;
			if(priBrojacB==0){priBrojacB-=brojac;}
			
		} else if (a=='s'||a=='S'){
			brojac++;
			sBrojac++;
			if(priBrojacS==0){priBrojacS-=brojac;}
			
		} else if (a=='v'||a=='V'){
			brojac++;
			vBrojac++;
			if(priBrojacV==0){priBrojacV-=brojac;}
			
		} else if (a=='p'||a=='P'){
			brojac++;
			pBrojac++;
			if(priBrojacP==0){priBrojacP-=brojac;}
			
		} else if (a=='K'||a=='k'){
			break;
		} else {
			printf ("Neispravan unos\n");
		}
		
	}
	
	
	
	

	float postC,postB,postS,postV,postP;
	float max;
	postC=(float)cBrojac/brojac*100;
	postB=(float)bBrojac/brojac*100;
	postS=(float)sBrojac/brojac*100;
	postV=(float)vBrojac/brojac*100;
	postP=(float)pBrojac/brojac*100;
	if(postC>=postB){
		max=postC;
	} else {
		max=postB;
	}
	
	if(postP>=max){
		max=postP;
	}
	
	if(postS>=max){
		max=postS;
	}
	if(postV>=max){
		max=postV;
	}
	
	
	
	int brojMin;
	if(priBrojacC>priBrojacB){
		brojMin=priBrojacC;
	} else {
		brojMin=priBrojacB;
	}
	if(brojMin<priBrojacS){
		brojMin=priBrojacS;
	}
	if(priBrojacV>brojMin){
		brojMin=priBrojacV;
	}
	if(priBrojacP>brojMin){
		brojMin=priBrojacP;	
	}
	printf("Ukupno evidentirano %d vozila.\n",brojac);
	if(brojac==0){
		printf("Najpopularnija boja je crna (0.00%).");
	}
	
	if( max==postC ){
		printf("Najpopularnija boja je crna (%.2f%%).", postC);
	} else if( max==postB /*&& brojMin==priBrojacB*/){
		printf("Najpopularnija boja je bijela (%.2f%%).", postB);
	} else if( max==postS /*&& brojMin==priBrojacS*/){
		printf("Najpopularnija boja je siva (%.2f%%).", postS);
	} else if( max==postV /*&& brojMin==priBrojacV*/){
		printf("Najpopularnija boja je crvena (%.2f%%).", postV);
	} else if( max==postP /*&& brojMin==priBrojacP*/){
		printf("Najpopularnija boja je plava (%.2f%%).", postP);
	} 
	
	return 0;
}
