#include <stdio.h>
#define PKKK 6.80
#define HKKK 3.30
#define CKKK 5.00
#define PFF  8.00
#define HFF  3.00
#define CFF  3.90
#define PB   5.30
#define HB   5.00
#define CB   6.00
int main() {
	
	float Uk,Uk1,Uk2,Uk3,Uk4,Uk5,Uk6,Uk7,Uk8,Uk9,r1,r2,r4,r5,r6,r7,r8,r9,r10;
	char jTarik,jBojan,jMirza,novi_Red;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&jTarik);
	scanf("%c",&novi_Red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&jBojan);
	scanf("%c",&novi_Red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&jMirza);
	
	if(jTarik=='H' && jMirza=='H' &&jBojan=='H'){
		Uk=3*HFF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",Uk);
		r1=3*HKKK*0.9;
		if(r1<Uk){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r1);
		}
	}
		else if(((jTarik=='H' && jBojan=='H') || (jMirza=='H' && jBojan=='H') || (jMirza=='H' && jTarik=='H')) && (jBojan=='P' || jMirza=='P' || jTarik=='P')){
		Uk2=2*HKKK+PKKK;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",Uk2);
	}
	else if(((jTarik=='H' && jBojan=='H') || (jMirza=='H' && jBojan=='H') || (jMirza=='H' && jTarik=='H')) && (jBojan=='C' || jMirza=='C' || jTarik=='C')){
		Uk1=2*HFF+CFF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",Uk1);
		r2=2*(HKKK*0.9)+CKKK;
		if(r2<Uk1){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r2);
		}
	}
	else if(jTarik=='C' && jBojan=='C' && jMirza=='C'){
		Uk3=3*CFF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",Uk3);
		r4=3*CKKK*0.9;
		if(r4<Uk3){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r4);
		}
	}
	else if(jTarik=='P' && jMirza=='P' && jBojan=='P'){
		Uk4=3*PB;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",Uk4);
		r5=3*PKKK*0.9;
		if(r5<Uk4){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r5);
		}
	}
	else if((jTarik=='P' && jMirza=='H' && jBojan=='C') || (jTarik=='P' && jMirza=='C' && jBojan=='H') || (jTarik=='H' && jMirza=='C' && jBojan=='P') || (jTarik=='H' && jMirza=='P' && jBojan=='C') || (jTarik=='C' && jMirza=='H' && jBojan=='P') || (jTarik=='C' && jMirza=='P' && jBojan=='H')){
		Uk5=HFF+CFF+PFF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",Uk5);
		r6=HKKK+CKKK+PKKK*0.9;
		if(r6<Uk5){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r6);
		}
	}
	else if(((jTarik=='C' && jBojan=='C') || (jMirza=='C' && jBojan=='C') || (jMirza=='C' && jTarik=='C')) && (jBojan=='H' || jMirza=='H' || jTarik=='H')){
		Uk6=2*CFF+HFF;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",Uk6);
		r7=2*CKKK*0.9+HKKK;
		if(r7<Uk6){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r7);
		}
	}
	else if(((jTarik=='C' && jBojan=='C') || (jMirza=='C' && jBojan=='C') || (jMirza=='C' && jTarik=='C')) && (jBojan=='P' || jMirza=='P' || jTarik=='P')){
        Uk7=2*CFF+PFF;
        printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",Uk7);
        r8=2*CKKK*0.9+PKKK;
        if(r8<Uk7){
        	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r8);
        }
	}
    else if(((jTarik=='P' && jBojan=='P') || (jMirza=='P' && jBojan=='P') || (jMirza=='P' && jTarik=='P')) && (jBojan=='H' || jMirza=='H' || jTarik=='H')){
    	Uk8=2*PB+HB;
    	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",Uk8);
    	r9=2*PKKK*0.9+HKKK;
    	if(r9<Uk8){
    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r9);
    	}
    }
    else if(((jTarik=='P' && jBojan=='P') || (jMirza=='P' && jBojan=='P') || (jMirza=='P' && jTarik=='P')) && (jBojan=='C' || jMirza=='C' || jTarik=='C')){
    	Uk9=2*PB+CB;
    	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",Uk9);
    	r10=2*PKKK*0.9+CKKK;
    	if(r10<Uk9){
    		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",r10);
    	}
    }
	return 0;
}
