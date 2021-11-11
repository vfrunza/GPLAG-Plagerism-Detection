#include <stdio.h>

int main() {
	char x;
	int crvena=0,crna=0,plava=0,siva=0,bijela=0,max=0,ukupno;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &x);
		if((int)x!=67 && (int)x!=99 && (int)x!=66 && (int)x!=98 && (int)x!=83 && (int)x!=115 && (int)x!=86 && (int)x!=118 && (int)x!=80 && (int)x!=112 && (int)x!=75 && (int)x!=107){
			
		printf("Neispravan unos \n");
		}
		if((int)x==67 || (int)x==99){
		crna++;	
		} else if((int)x==86 || (int)x==118){
		crvena++;	
		} else if((int)x==80 || (int)x==112){
		plava++;	
		} else if((int)x==83 || (int)x==115){
		siva++;	
		} else if((int)x==66 || (int)x==98){
		bijela++;	
		}
		}while((int)x!=75 && (int)x!=107);
		ukupno=crna+crvena+plava+bijela+siva;
		if(ukupno==0){
			printf("Ukupno evidentirano 0 vozila.\n");
			printf("Najpopularnija boja je crna (0.00%%).");
			return 0;
		}
        max=0;
		if(plava>max){
			max=plava;
		}
	 if(crvena>=max){
			max=crvena;
		}
	 if(siva>=max){
			max=siva;
		}
	 if(bijela>=max){
			max=bijela;
		}
		
	 if(crna>=max){
			max=crna;
		}
		
		printf("Ukupno evidentirano %d vozila. \n", ukupno);
		if(max==crna){
			printf("Najpopularnija boja je crna (%.2f%%).",((float)crna/ukupno)*100);
		return 0;
			
		} 
		else if(max==bijela){
			printf("Najpopularnija boja je bijela (%.2f%%).",((float)bijela/ukupno)*100);
			return 0;
		}
		 else  if(max==siva){
			printf("Najpopularnija boja je siva (%.2f%%).",((float)siva/ukupno)*100);
			return 0;
		}
	
		else if(max==crvena){
			printf("Najpopularnija boja je crvena (%.2f%%).",((float)crvena/ukupno)*100);
			return 0;
		} 
	
	    else if(max==plava){
			printf("Najpopularnija boja je plava (%.2f%%).",((float)plava/ukupno)*100);
		}
		
	return 0;
}
