#include <stdio.h>
#define eps 0.0001
int main()
{
	char tarik, bojan, mirza, nr;
	float RP=6.80, RH=3.30, RC=5.00, TP=8.00, TH=3.00, TC=3.90, BP=5.30, BH=5.00, BC=6.00, R, B, T;
	int brham=0,brpiz=0,brcev=0;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &nr);

	switch(tarik) {
	case 'P':
		brpiz++;
		break;
	case 'H':
		brham++;
		break;
	case 'C':
		brcev++;
		break;
	}

	switch(bojan) {
	case 'P':
		brpiz++;
		break;
	case 'H':
		brham++;
		break;
	case 'C':
		brcev++;
		break;
	}

	switch(mirza) {
	case 'P':
		brpiz++;
		break;
	case 'H':
		brham++;
		break;
	case 'C':
		brcev++;
		break;
	}


	R=RP*brpiz+RH*brham+RC*brcev;
	T=TP*brpiz+TH*brham+TC*brcev;
	B=BP*brpiz+BH*brham+BC*brcev;


	if (B>=R && T>=R)
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",R);
	
	else if (R>=T && B>=T) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",T);
		if (brcev>=1 && brpiz==0) {
			R=RH*brham+RC*0.9*brcev;
			if(R<T && R<B)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R);
		} 
		else if (brpiz>=1) {
			R=RP*0.9*brpiz+RH*brham+RC*brcev;
			if(R<T && R<B)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R);
		} 
		else {
			R=RH*0.9*brham;
			if(R<T && R<B)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R);
		}
	} 
	else {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",B);
		if (brcev>=1 && brpiz==0) {
			R=RH*brham+RC*0.9*brcev;
			if(R<T && R<B)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R);
		} 
		else if (brpiz>=1) {
			R=RP*0.9*brpiz+RH*brham+RC*brcev;
			if(R<T && R<B)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R);
		} 
		else {
			R=RH*0.9*brham;
			if(R<T && R<B)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",R);
		}
	}

	return 0;
}
