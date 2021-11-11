#include <stdio.h>
#define p1 6.8
#define p2 8.0
#define p3 5.3
#define h1 3.3 
#define h2 3.0
#define h3 5.0
#define c1 5.0
#define c2 3.9
#define c3 6.0

int main() {
 
 char tarik, bojan, mirza;
	
	double ceh1,ceh2,ceh3,ceh,t,srecko;
	
	ceh1 = 0, ceh2 = 0, ceh3 = 0, ceh = 0;
	
	printf("Unesite jelo za Tarika: ");
	tarik = getchar();getchar();
	printf("Unesite jelo za Bojana: ");
	bojan = getchar();getchar();
	printf("Unesite jelo za Mirzu: ");
	mirza = getchar();
	
	switch(tarik){
		case 'P':
			ceh1 += p1;
			ceh2 += p2; 
			ceh3 += p3;
		    break;
		case 'H':
			ceh1 += h1;
			ceh2 += h2;
			ceh3 += h3;
			break;
		case 'C':
			ceh1 += c1; 
			ceh2 += c2;
			ceh3 += c3;
			break;
		
	}

	switch(bojan){
		case 'P':
			ceh1 += p1;
			ceh2 += p2;
			ceh3 += p3;
			break;
		case 'H':
			ceh1 += h1;
			ceh2 += h2;
			ceh3 += h3;
			break;
		case 'C':
			ceh1 += c1;
			ceh2 += c2;
			ceh3 += c3;
			break;
	}


	switch(mirza){
		case 'P':
			ceh1 += p1;
			ceh2 += p2;
			ceh3 += p3;
			break;
		case 'H':
			ceh1 += h1;
			ceh2 += h2;
			ceh3 += h3;
			break;
		case 'C':
			ceh1 += c1;
			ceh2 += c2;
			ceh3 += c3;
			break;
	}
	
	if(bojan == tarik && tarik == mirza )srecko=ceh1;
		else if((ceh1-13.30)*(ceh1-13.30)<0.000001)srecko=10;
		else if((ceh1-11.60)*(ceh1-11.60)<0.000001)srecko=6.6;
		else if((ceh1-16.90)*(ceh1-16.90)<0.000001)srecko=13.6;
		else if((ceh1-13.40)*(ceh1-13.40)<0.000001)srecko=6.8;
		else if((ceh1-16.80)*(ceh1-16.80)<0.000001)srecko=10;
		else if((ceh1-18.60)*(ceh1-18.60)<0.000001)srecko=13.6;
		else srecko=6.8;
		ceh = ceh1;
		if(ceh > ceh2)ceh = ceh2;
		if(ceh > ceh3)ceh = ceh3;
		t=ceh1-srecko*0.1;
		
		if((ceh - ceh1)*(ceh - ceh1) < 0.000001)
		{
			printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).",34,34,ceh );
		}
		else if((ceh - ceh2)*(ceh - ceh2) < 0.000001)
		{
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).",34,34,ceh);
			if(t < ceh)printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",t);
		}
		else if((ceh - ceh3)*(ceh - ceh3) < 0.000001)
		{
			printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).",34,34,ceh);
			if(t < ceh)printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",t);
		}

	
	
	return 0;
}
