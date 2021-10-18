#include <stdio.h>

int main() {

	char T,B,M;
	char novi_red;
	float pr,hr,cr,pf,hf,cf,pb,hb,cb;
	double restuk, fastuk, bistuk;
	float pizza,hamb,cevapi;
	pr=6.80;
	hr=3.30;
	cr=5.00;
	pf=8.00;
	hf=3.00;
	cf=3.90;
	pb=5.30;
	hb=5.00;
	cb=6.00;
	restuk=0;
	fastuk=0;
	bistuk=0;
	pizza=0;
	hamb=0;
	cevapi=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c",&novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c",&novi_red);
	
	switch (T){
		case 'P':
		restuk+=pr;
		fastuk+=pf;
		bistuk+=pb;
		pizza++;
		break;
		case 'H':
		restuk+=hr;
		fastuk+=hf;
		bistuk+=hb;
		hamb++;
		break;
		case 'C':
		restuk+=cr;
		fastuk+=cf;
		bistuk+=cb;
		cevapi++;
		break;
	}
	switch (M){
		case 'P':
		restuk+=pr;
		fastuk+=pf;
		bistuk+=pb;
		pizza++;
		break;
		case 'H':
		restuk+=hr;
		fastuk+=hf;
		bistuk+=hb;
		hamb++;
		break;
		case 'C':
		restuk+=cr;
		fastuk+=cf;
		bistuk+=cb;
		cevapi++;
		break;
	}
	switch (B){
		case 'P':
		restuk+=pr;
		fastuk+=pf;
		bistuk+=pb;
		pizza++;
		break;
		case 'H':
		restuk+=hr;
		fastuk+=hf;
		bistuk+=hb;
		hamb++;
		break;
		case 'C':
		restuk+=cr;
		fastuk+=cf;
		bistuk+=cb;
		cevapi++;
		break;
	}


	if (restuk<=fastuk && restuk<bistuk){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restuk);
		return 0;
	}
	else if (fastuk<restuk && fastuk<bistuk){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",fastuk);

	}
	else if (bistuk<fastuk && bistuk<restuk){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bistuk);

	}
	
	if (pizza*pr>hamb*hr && pizza*pr>cevapi*cr){
		restuk=restuk-0.1*pizza*pr;
		
	}
	else if (hamb*hr>pizza*pr && hamb*hr>cevapi*cr){
		restuk=restuk-0.1*hamb*hr;

	
	}
	else if (cevapi*cr>pizza*pr && cevapi*cr>hamb*hr){
		restuk=restuk-0.1*cevapi*cr;
		
	
	}

	if (restuk<fastuk && restuk<bistuk){
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restuk);
	}
	
	
	return 0;
}
