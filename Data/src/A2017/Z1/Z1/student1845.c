#include <stdio.h>

int main() {
	char t,b,m,n;
	double K,T,B,KSP;
	int hambas=0,pica=0,vapace=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &n);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &n);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &n);
	if(t=='H') hambas++;
	else if(t=='P') pica++;
	else if(t=='C') vapace++;
		if(b=='H') hambas++;
	else if(b=='P') pica++;
	else if(b=='C') vapace++;
		if(m=='H') hambas++;
	else if(m=='P') pica++;
	else if(m=='C') vapace++;
	
	K=pica*6.8+hambas*3.3+vapace*5.0;
	T=pica*8.0+hambas*3.0+vapace*3.90;
	B=pica*5.30+hambas*5.0+vapace*6.0;
	
	if(pica>=1 && pica<=3) {
		KSP=((pica*6.8)-((pica*6.8)/10))+hambas*3.3+vapace*5.0;
	}
	else if(vapace>=1 && vapace<=3 && pica==0) {
		KSP=((vapace*5.0)-((vapace*5.0)/10))+hambas*3.3+pica*6.8;
	}
	else if(hambas>=1 && hambas<=3 && pica==0 && vapace==0) {
		KSP=((hambas*3.3)-((hambas*3.3)/10))+pica*6.8+vapace*5.0;
	}
	if(K<T && K<B) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).", K);
	else if(T<K && T<B) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", T);
		if(KSP<T) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", KSP);
	}
	else if(B<K && B<T) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).\n", B );
		if(KSP<B) printf("Sa popustom bi Restoran bio jeftiniji (%.2lf KM).", KSP);
	}
	return 0;
}
