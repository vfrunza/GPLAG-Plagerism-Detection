#include <stdio.h>
#include <math.h>
int main(){
	double proc1=0, proc2=0, proc3=0, proc4=0, proc5=0, brauta=0, brc=0, brb=0, brs=0, brv=0, brp=0;
	char znak;
	printf("Unesite vozila: ");
	while(1==1){
		scanf("%c", &znak);
		if(znak=='C' || znak=='c'){
			brc++;
			brauta++;
		}
		else if(znak=='B' || znak=='b'){
			brb++;
			brauta++;
		}
		else if(znak=='S' || znak=='s'){
			brs++;
			brauta++;
		}
		else if(znak=='V' || znak=='v'){
			brv++;
			brauta++;
		}
		else if(znak=='P' || znak=='p'){
			brp++;
			brauta++;
	    }
	    else if(znak=='K' || znak=='k'){
	    	break;
	    }
	    else {
	    	printf("Neispravan unos\n");
	    }
	}
	printf("Ukupno evidentirano %.lf vozila.", brauta);

	if(brc>=brb && brc>=brs && brc>=brv && brc>=brp){
		proc1=(brc/brauta)*100;
		if(brc==0){
			printf("\nNajpopularnija boja je crna (0.00%%).");
		}
		else{
	      printf("\nNajpopularnija boja je crna (%.2lf%%).", proc1);
		}
	}
	else if(brb>brc && brb>=brs && brb>=brv && brb>=brp){
		proc2=(brb/brauta)*100;
	    printf("\nNajpopularnija boja je bijela (%.2lf%%).", proc2);
	}
	else if(brs>brc && brs>brb && brs>=brv && brs>=brp){
		proc3=(brs/brauta)*100;
	    printf("\nNajpopularnija boja je siva (%.2lf%%).", proc3);
	}
	else if(brv>brc && brv>brb && brv>brs && brv>=brp){
		proc4=(brv/brauta)*100;
	    printf("\nNajpopularnija boja je crvena (%.2lf%%).", proc4);
	}
	else if(brp>brc && brp>brb && brp>brs && brp>brv){
		proc5=(brp/brauta)*100;
	    printf("\nNajpopularnija boja je plava (%.2lf%%).", proc5);
    }
    return 0;
}