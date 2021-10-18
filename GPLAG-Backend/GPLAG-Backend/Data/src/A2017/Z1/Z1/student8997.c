#include <stdio.h>


int main() {
			char C,H,P,Tarik,Bojan,Mirza,novi_red;
			float S=0,S1=0,S2=0,S3=0,T,B,M;
			printf("Unesite jelo za Tarika: ");
			scanf("%c", &Tarik);
		    scanf("%c", &novi_red);
			printf("Unesite jelo za Bojana: ");
			
			scanf("%c", &Bojan);
			scanf("%c", &novi_red);
			printf("Unesite jelo za Mirzu: ");
			
			scanf("%c", &Mirza);
			scanf("%c", &novi_red);
			if(Tarik=='H'){
				S+=3.3;			 
				S1+=3.0;
				S2+=5.0;
				T=3.3;
}
			if(Mirza=='H'){
				S+=3.3;			
				S1+=3.0;
				S2+=5.0;
				M=3.3;
			}
			if(Bojan=='H'){
				S+=3.3;			
				S1+=3.0;
				S2+=5.0;
				B=3.3;
			}
			//printf("Suma: %d", S);
			
				if(Tarik=='P'){
				S+=6.8;			
				S1+=8.0;
				S2+=5.3;
				T=6.8;
			}
				if(Mirza=='P'){
				S+=6.8;			
				S1+=8.0;
				S2+=5.3;
				M=6.8;
			}
				if(Bojan=='P'){
				S+=6.8;			
				S1+=8.0;
				S2+=5.3;
				B=6.8;
			}
				if(Tarik=='C'){
				S+=5.0;			
				S1+=3.9;
				S2+=6.0;
				T=5.0;
			}
				if(Mirza=='C'){
				S+=5.0;			
				S1+=3.9;
				S2+=6.0;
				M=5.0;
			}
				if(Bojan=='C'){
				S+=5.0;			
				S1+=3.9;
				S2+=6.0;
				B=5.0;
			}
			//printf("Suma: %f %f %f", S,S1,S2);
			if(S<S1 && S<S2) {
				printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM). ", S);
				
			}
			
			if(M!=T && M!=B && T!=B) {
				if(T>B && T>M) {
					T=T-T/10;
					
				} else if (B>T && B>M) {
					B=B-B/10;
				} else {
					M=M-M/10;
				}
			} else if (M==T && B!=T) {
				if(M+T>B) {
					M=M-M/10;
					T=T-T/10;
					
				} else B=B-B/10;
			}
			else if (T==B && M!=T) {
				if(B+T>M) {
					B=B-B/10;
					T=T-T/10;
					
				} else M=M-M/10;
			}
			
			else if (M==B && T!=B) {
				if(M+B>T) {
					M=M-M/10;
					B=B-B/10;
					
				} else T=T-T/10;
			}
			else if (M==T && B==T) {
				 {
					M=M-M/10;
					T=T-T/10;
					
				}  B=B-B/10;
			}
			
			
			
				S3=M+B+T;
			if(S1<S && S1<S2) {
					printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", S1);
				
				if(S3<S1) {
					printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM). ", S3);
				}
					
				
			
			}
			
			
			if((S2<S1) && (S2<S)) {
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", S2);
				
				if(S3<S2) {
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", S3);
				}
				
					
				}
				
				
			
			
	return 0;
}
