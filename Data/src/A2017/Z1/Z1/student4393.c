#include <stdio.h>

int main() {
	char C,H,P,tarik,bojan,mirza,novi_red;
	float K=0,Tr=0,L=0,t,b,m,brojac=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	if(tarik=='H') {
		K+=3.30;
		Tr+=3.00;
		L+=5.00;
		t=3.30;
	}
	if(bojan=='H') {
		K+=3.30;
		Tr+=3.00;
		L+=5.00;
		b=3.30;
	}
	if(mirza=='H') {
		K+=3.30;
		Tr+=3.00;
		L+=5.00;
		m=3.30;
	}
	if(tarik=='P') {
		K+=6.80;
		Tr+=8.00;
		L+=5.30;
		t=6.80;
	}
	if(bojan=='P') {
		K+=6.80;
		Tr+=8.00;
		L+=5.30;
		b=6.80;
	}
	if(mirza=='P') {
		K+=6.80;
		Tr+=8.00;
		L+=5.30;
		m=6.80;
	}
	if(tarik=='C') {
		K+=5.00;
		Tr+=3.90;
		L+=6.00;
		t=5.00;
		}
	if(bojan=='C') {
		K+=5.00;
		Tr+=3.90;
		L+=6.00;
		b=5.00;
	}
	if(mirza=='C') {
		K+=5.00;
		Tr+=3.90;
		L+=6.00;
		m=5.00;
	}
	if(K<Tr && K<L){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",K);
	}
	if(m!=t && m!=b && t!=b) {
		if(t>b && t>m){
			t=t-t/10;
		}
		else if(b>t && b>m) {
			b=b-b/10;
		}
		else {
			m=m-m/10;
		}
	}
	else if(m==t && b!=t) {
		if(m+t>b) {
			t=t-t/10;	                
			m=m-m/10;                 
		}
		else b=b-b/10;
	}
	else if(t==b && m!=t) {
		if(b+t>m) {
			t=t-t/10;
			b=b-b/10;
		}
		else m=m-m/10;
	}
	else if(m==b && t!=b) {
		if(m+b>t) {
			b=b-b/10;
			m=m-m/10;
    	}
    	else t=t-t/10;
	}
	else if(m==t && b==t) {
		{
			t=t-t/10;
			m=m-m/10;
		}
		b=b-b/10;
	}
	brojac=t+b+m;
	if(Tr<K && Tr<L) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",Tr);
		if(brojac<Tr) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",brojac);
		}
	}
	if((L<Tr) && (L<K)) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",L);
	if(brojac<L) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",brojac);
	    }
	}	
	return 0;
}
