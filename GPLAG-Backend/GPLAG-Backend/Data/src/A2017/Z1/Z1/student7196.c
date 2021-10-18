#include <stdio.h>

int main() {
	char t, b, m, nr;
	float CR=0, CFF=0, CB=0, MINC;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &nr);
	switch (t) {
		case 'P':
			CR+=6.8;
			CFF+=8.0;
			CB+=5.3;
			break;
		case 'H':
			CR+=3.3;
			CFF+=3.0;
			CB+=5.0;
			break;
		case 'C':
			CR+=5.0;
			CFF+=3.9;
			CB+=6.0;
			break;
	}
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &nr);
	switch (b) {
		case 'P':
			CR+=6.8;
			CFF+=8.0;
			CB+=5.3;
			break;
		case 'H':
			CR+=3.3;
			CFF+=3.0;
			CB+=5.0;
			break;
		case 'C':
			CR+=5.0;
			CFF+=3.9;
			CB+=6.0;
			break;
	}
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &nr);
	switch (m) {
		case 'P':
			CR+=6.8;
			CFF+=8.0;
			CB+=5.3;
			break;
		case 'H':
			CR+=3.3;
			CFF+=3.0;
			CB+=5.0;
			break;
		case 'C':
			CR+=5.0;
			CFF+=3.9;
			CB+=6.0;
			break;
	}
	
	MINC=CR;
	if(CFF<MINC) {
		MINC=CFF;
	}
	if (CB<MINC) {
		MINC=CB;
	}
	
	if (MINC==CR) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", CR);
	}
	if (MINC==CFF) {
			printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", CFF);
	}
	if (MINC==CB) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", CB);
	}
	
	if (MINC!=CR) {
		float NCR=0;
		int bup=0, buh=0, buc=0;
		if (t=='P' || b=='P' || m=='P') {
			if (t=='P') {
				bup++;
			}
			if (b=='P') {
				bup++;
			}
			if (m=='P') {
				bup++;
			}
			NCR=CR-bup*0.68;
		}
		else if (t=='C' || b=='C' || m=='C') {
			if (t=='C') {
				buc++;
			}
			if (b=='C') {
				buc++;
			}
			if (m=='C') {
				buc++;
			}
			NCR=CR-buc*0.5;
		}
		else {
			NCR=CR-0.99;
		}
		if (NCR<MINC) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", NCR);
		}
	}
	return 0;
}
