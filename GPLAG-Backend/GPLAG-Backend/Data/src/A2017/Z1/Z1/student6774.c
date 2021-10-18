#include <stdio.h>
#include <math.h>
#define PK 6.80
#define PT 8.00
#define PL 5.30
#define HK 3.30
#define HT 3.00
#define HL 5.00
#define CK 5.00
#define CT 3.90
#define CL 6.00



int main() {
 signed	char T, B, M,  novi_red; 
	float H=0, P=0, C=0, K=0, L=0,t=0, U=0, Z=0 ;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &novi_red);
	if ('H'== T){
		H=H+1;
	}
	if ('P'==T){
		P=P+1;
	}
	if ('C'==T){
		C=C+1;
	}
	if ('H'==B){
		H=H+1;
	}
	if ('P'==B){
		P=P+1;
	}
	if ('C'==B){
		C=C+1;
	}
	if ('H'==M){
		H=H+1;
	}
	if ('P'==M){
		P=P+1;
	}
	if ('C'==M){
		C=C+1;
	}
	K= H*HK + P*PK+C*CK;
	t= H*HT + P*PT+C*CT;
	L= H*HL + P*PL+C*CL;
	if (P==3)Z=PK*P-0.1*PK*P;
	if (H==3)Z=HK*H-0.1*HK*H;
	if (C==3)Z=CK*C-0.1*CK*C;
	if ((H==2)&&(P==1))Z=HK*H+PK*P-0.1*PK*P;
	if ((H==2)&&(C==1))Z=HK*H+CK*C-0.1*CK*C;
	if ((P==2)&&(C==1))Z=PK*P+CK*C-0.1*PK*P;
	if ((P==2)&&(H==1))Z=PK*P+HK*H-0.1*PK*P;
	if ((C==2)&&(P==1))Z=CK*C+PK*P-0.1*PK*P;
	if ((C==2)&&(H==1))Z=CK*C+HK*H-0.1*CK*C;
	if ((H==1)&&(P==1)&&(C==1))Z=HK*H+PK*P+CK*C-0.1*PK*P;
	if ((t<K)&&(t<L)){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", t);
		if(Z<t)printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Z);
		
	}
	if ((K<t)&&(K<L)){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",K);
	}
	if ((L<t)&&(L<K)){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", L);
		if(Z<L)printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Z);
	}

	return 0;
}
