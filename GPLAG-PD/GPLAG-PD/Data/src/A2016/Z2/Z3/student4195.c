#include <stdio.h>
#define MAX_EL 20

int main() {
	/*Podesimo sve elemente koordinatnog sistema na 0*/
	int koord_sistem[MAX_EL][MAX_EL] = {0},x,y,broj_tacaka,i,j;
	
	/*Prvo provjerimo da li je uopste broj tacaka u rangu [1,10]*/
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&broj_tacaka);
		if(broj_tacaka<=0 || broj_tacaka>10)
			printf("Pogresan unos\n");
	}while(broj_tacaka<=0 || broj_tacaka>10);
		
	/*Pocnimo sa unosom tacaka i provjerimo da li je svaka tacka u rangu [0,19]*/
		for(i=0; i<broj_tacaka; i++) {
			do{	
				printf("Unesite %d. tacku: ",i+1);
				scanf("%d %d",&x,&y);
				if(x<0 || x>19 || y<0 || y>19){
					printf("Pogresan unos\n");
				}
			}while(x<0 || x>19 || y<0 || y>19);	
			/* Na mjesto x,y matrice, gdje su x i y koordinate tacke, stavimo jedinicu, da oznacimo to mjesto */
			koord_sistem[x][y] = 1;
				
		}
	/* Sad jos samo ispisimo zvjezdicu na svakom mjestu matricu gdje smo stavili 1, tj. na mjesta onih tacaka iz prethodnog koraka*/
	for (i=0; i<20; i++) {
		for(j=0;j<20;j++) {
			/*Ovdje nam je bitno da je prva koordinata kolona a druga red pri provjeri, jer je koordinatni sistem takav
			  da je uvijek prva tacka kolona a druga red, pa stoga pisemo prvo j pa onda i */
			if(koord_sistem[j][i]==1)
				printf("*");
			else
				printf(" ");
			
		}
		printf("\n");
	}

	return 0;
}
