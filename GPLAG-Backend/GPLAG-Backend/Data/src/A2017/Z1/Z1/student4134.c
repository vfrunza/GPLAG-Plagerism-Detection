#include <stdio.h>
#include <math.h>

int main() {
	char T, B, M,N;
	double  restoran=0,restoran1=0,restoran2=0, restoran3=0;
	double  fastfood=0;
	double  bistro=0;
	double min=0;

	
	printf("Unesite jelo za Tarika: ");
	scanf("%c%c",&T,&N);
	printf("Unesite jelo za Bojana: ");
	scanf("%c%c",&B,&N);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c%c",&M,&N);

			if(T=='P'){
	restoran+=6.8;
	restoran1+=6.8-6.8*0.1;
	restoran2+=6.8;
	restoran3+=6.8;
	fastfood+=8;
	bistro+=5.3;}
			
			
			else if(T=='H'){
	restoran+=3.3;
	restoran2+=3.3-3.3*0.1;
	restoran1+=3.3;
	restoran3+=3.3;
	fastfood+=3;
	bistro+=5;
			}
			
		
		
			
		 else if(T=='C'){
	restoran+=5;
	restoran3+=5-5*0.1;
	restoran1+=5;
	restoran2+=5;
	fastfood+=3.9;
	bistro+=6;
			}
			
		
			
			
			 if(B=='P'){
			restoran+=6.8;
	restoran1+=6.8-6.8*0.1;
	restoran2+=6.8;
	restoran3+=6.8;
	fastfood+=8;
	bistro+=5.3;
			}
			
			else if( B=='H'){
	restoran+=3.3;
	restoran2+=3.3-3.3*0.1;
	restoran1+=3.3;
	restoran3+=3.3;
	fastfood+=3;
	bistro+=5;
			}
			
			else if( B=='C'){
	restoran+=5;
	restoran3+=5-5*0.1;
	restoran1+=5;
	restoran2+=5;
	fastfood+=3.9;
	bistro+=6;
			}
			
			 if(M=='P'){
	restoran+=6.8;
	restoran1+=6.8-6.8*0.1;
	restoran2+=6.8;
	restoran3+=6.8;
	fastfood+=8;
	bistro+=5.3;
			}
			
			
			else if( M=='H'){
	restoran+=3.3;
	restoran2+=3.3-3.3*0.1;
	restoran1+=3.3;
	restoran3+=3.3;
	fastfood+=3;
	bistro+=5;
			}
			
			else if(M=='C' ){
		restoran+=5;
	restoran3+=5-5*0.1;
	restoran1+=5;
	restoran2+=5;
	fastfood+=3.9;
	bistro+=6;
			}
			

	if(fabs(restoran1)>0.00001)min=restoran1;
	else if(fabs(restoran2)>0.00001)min=restoran2;
	else min=restoran3;
	if(min>restoran1)min=restoran1;
	if(min>restoran2)min=restoran2;
	if(min>restoran3)min=restoran3;
	
		if (restoran<fastfood && restoran<bistro) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran);
		else if (fastfood<restoran && fastfood<bistro){ printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",fastfood);
		if(min<fastfood && min<bistro){
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
		}
			
		}else if(bistro<restoran && bistro<fastfood){
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",bistro);
			if(min<fastfood && min <bistro){
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",min);
			}
		}
	    	return 0;
}