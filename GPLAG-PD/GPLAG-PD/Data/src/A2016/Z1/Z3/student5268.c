#include <stdio.h>

int main() {
	char znak;
	float post;
	int bel=0,max=0,bl=0,crn=0,siv=0,red=0,ub=0;
	printf("Unesite vozila: ");
	znak=getchar();
	while(znak!='k' && znak!='K'){
		
		if(znak=='c' || znak=='C'){
			crn++;
			ub++;
			if(crn>max){
		    	max=crn;
			}
		}
		else if(znak=='B' || znak=='b'){
			bel++;
			ub++;
			if(bel>max){
				max=bel;
			}
		}
	
		
		else if(znak=='s' || znak=='S'){
			siv++;
			ub++;
			if(siv>max){
				max=siv;
			}
		}
			else if(znak == 'V' || znak=='v'){
			red++;
			ub++;
			if(red>max){
				max=red;
			}
		}
		else if(znak=='P' || znak=='p'){
			bl++;
			ub++;
			if(bl>max){
				max=bl;
				
			}
		}
		else printf("Neispravan unos\n");
		
	  	
		znak=getchar();
		
	}
	post=(float)max/(float)ub*100;
		printf("Ukupno evidentirano %d vozila.\n",ub);
		if (ub==0){
			printf("Najpopularnija boja je crna (0.00%).");
		}
	else if(max==bel ){
		printf("Najpopularnija boja je bijela (%.2f%).",post);
	}
	else if(max==crn ){
		printf("Najpopularnija boja je crna (%.2f%).",post);
	}
	else if(max==bl){
		printf("Najpopularnija boja je plava (%.2f%).",post);
	}
	else if(max==red ){
		printf("Najpopularnija boja je crvena (%.2f%).",post);
	}
	else if(max==siv){
		printf("Najpopularnija boja je siva (%.2f%).",post);
	}
	
	return 0;
}
