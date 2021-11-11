#include <stdio.h>

//RESTORAN
#define RP 6.80
#define RH 3.30
#define RC 5.00
//FAST-FOOD
#define FP 8.00
#define FH 3.00
#define FC 3.90
//BISTRO
#define BP 5.30
#define BH 5.00
#define BC 6.00

int main() {
	char tarik, bojan, mirza, novi_red;
	char zarez='"';
	double suma1=0, suma2=0, suma3=0, popust1, popust2, popust3;
	double suma1p=0, suma2p=0, suma3p=0;
	int i, j;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	popust1=(RP/10.)*9;
	popust2=(RH/10.)*9;
	popust3=(RC/10.)*9;
	
	if(tarik=='H') {
		suma1+=RH;
		suma2+=FH;
		suma3+=BH;
	} else {
		if(tarik=='P') {
			suma1+=RP;
			suma2+=FP;
			suma3+=BP;
		} else {
			if(tarik=='C') {
				suma1+=RC;
				suma2+=FC;
				suma3+=BC;
			}
		}
	}
	
	if(bojan=='H') {
		suma1+=RH;
		suma2+=FH;
		suma3+=BH;
	} else {
		if(bojan=='P') {
			suma1+=RP;
			suma2+=FP;
			suma3+=BP;
		} else {
			if(bojan=='C') {
				suma1+=RC;
				suma2+=FC;
				suma3+=BC;
			}
		}
	}
	
	if(mirza=='H') {
		suma1+=RH;
		suma2+=FH;
		suma3+=BH;
	} else {
		if(mirza=='P') {
			suma1+=RP;
			suma2+=FP;
			suma3+=BP;
		} else {
			if(mirza=='C') {
				suma1+=RC;
				suma2+=FC;
				suma3+=BC;
			}
		}
	}
	
	if(suma1<suma2 && suma1<suma3) {
		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).", zarez, zarez, suma1);
		i=1;
	} else {
		if(suma2<suma1 && suma2<suma3) {
			printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).", zarez, zarez, suma2);
			i=2;
		} else {
			if(suma3<suma1 && suma3<suma2) {
				printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).", zarez, zarez, suma3);
				i=3;
			}
		}
	}
	
	j=0;
	while(j<3) {
		if((j==0 && bojan=='H') || (j==1 && mirza=='H') || (j==2 && tarik=='H')) {
			suma1p+=popust2;
		} else {
			if((j==0 && bojan=='P') || (j==1 && mirza=='P') || (j==2 && tarik=='P')) {
				suma1p+=RP;
			} else {
				if((j==0 && bojan=='C') || (j==1 && mirza=='C') || (j==2 && tarik=='C')) {
					suma1p+=RC;
				}
			}
		}
		j++;
	}
	if(suma1p<suma1) suma1=suma1p;
	j=0;
	while(j<3) {
		if((j==0 && bojan=='H') || (j==1 && mirza=='H') || (j==2 && tarik=='H')) {
			suma2p+=RH;
		} else {
			if((j==0 && bojan=='P') || (j==1 && mirza=='P') || (j==2 && tarik=='P')) {
				suma2p+=popust1;
			} else {
				if((j==0 && bojan=='C') || (j==1 && mirza=='C') || (j==2 && tarik=='C')) {
					suma2p+=RC;
				}
			}
		}
		j++;
	}
	if(suma2p<suma1) suma1=suma2p;
		j=0;
		while(j<3) {
			if((j==0 && bojan=='H') || (j==1 && mirza=='H') || (j==2 && tarik=='H')) {
				suma3p+=RH;
			} else {
				if((j==0 && bojan=='P') || (j==1 && mirza=='P') || (j==2 && tarik=='P')) {
					suma3p+=RP;
				} else {
					if((j==0 && bojan=='C') || (j==1 && mirza=='C') || (j==2 && tarik=='C')) {
						suma3p+=popust3;
					}
				}
			}
			j++;
		}
	if(suma3p<suma1) suma1=suma3p;
	if(i==2 && suma1<suma2)  {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma1);
		return 0;
	}
	if(i==3 && suma1<suma3) {
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma1);
		return 0;
	}
	return 0;
}
