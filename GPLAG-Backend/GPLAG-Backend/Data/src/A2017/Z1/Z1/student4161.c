#include <stdio.h>

int main() {
	int pizza=0, hamb=0, cevapi=0;
	char tarik, mirza, bojan, red;
	float restoran=0, trovac=0, lorelei=0, min=100;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&red);
	
	switch(tarik){
		case 'P':
		pizza++;
		break;
		
		case 'H':
		hamb++;
		break;
		
		case 'C':
		cevapi++;
		break;
	}
	switch(mirza){
		case 'P':
		pizza++;
		break;
		
		case 'H':
		hamb++;
		break;
		
		case 'C':
		cevapi++;
		break;
	}
	switch(bojan){
		case 'P':
		pizza++;
		break;
		
		case 'H':
		hamb++;
		break;
		
		case 'C':
		cevapi++;
		break;
	}
	
	restoran+=pizza*6.8+hamb*3.3+cevapi*5;
	trovac+=pizza*8+hamb*3+cevapi*3.9;
	lorelei+=pizza*5.3+hamb*5+cevapi*6;
	
	if(restoran<min) min=restoran;
	if(trovac<min) min=trovac;
	if(lorelei<min) min=lorelei;
	
    if(min==trovac) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
	else if(min==lorelei) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
	else if(min==restoran) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
	
	if(min!=restoran){
		if(pizza>0) restoran-=(6.8/10)*pizza;
		else if(hamb>0) restoran-=(3.3/10)*hamb;
		else restoran-=(5./10)*cevapi;
		if(min>=restoran) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran);
	}
	return 0;
}
