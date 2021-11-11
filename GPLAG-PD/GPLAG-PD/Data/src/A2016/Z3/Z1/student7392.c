#include <stdio.h>

/* NALAZENJE PROSTIH */
int daj_prost(){
	int i;
	static int broj=2;
	while(1){
		for(i=2;i<broj;i++){
			if(broj%i==0)break;
		}
		if(i==broj){
			broj++;
			return broj-1;
		} else broj++;
		if(broj<0)return 0;
	}
}

int main() {
	int donjaGranica, gornjaGranica;
	int suma=0;
	int trenutni;
	/* UNOS */
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &donjaGranica, &gornjaGranica);
		if(donjaGranica<1){
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(donjaGranica>=gornjaGranica){
			printf("A nije manje od B.\n");
			continue;
		}
		if(donjaGranica<1){
			printf("B nije prirodan broj.\n");
			continue;
		}
		break;
	}while(1);
	/* SABIRANJE PROSTIH */
	while(1){
		trenutni=daj_prost();
		if(trenutni>donjaGranica && trenutni<gornjaGranica)suma+=trenutni;
		if(trenutni>=gornjaGranica || trenutni==0)break;
	}
	/* ISPIS */
	printf("Suma prostih brojeva izmedju %d i %d je %d.", donjaGranica, gornjaGranica, suma);
	return 0;
}
