#include <stdio.h>
#define BROJ_EL 100

int main() {
	int nizA[BROJ_EL][BROJ_EL], nizB[BROJ_EL][BROJ_EL], nizC[BROJ_EL][BROJ_EL],tempB,tempB_br=0,tempC,tempC_br=0,tempAB_br=0,tempAC_br=0;
	int i, j, sirina, visina,j_pomoc,i_pomoc;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &visina, &sirina);
	}while((visina<0)||(visina>BROJ_EL)||(sirina<0)||(sirina>BROJ_EL));
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < visina; i++)
		for (j = 0; j < sirina; j++)
			scanf("%d",&nizA[i][j]);

	
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < visina; i++)
		for (j = 0; j < sirina; j++)
			scanf("%d",&nizB[i][j]);

	
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < visina; i++)
		for (j = 0; j < sirina; j++)
			scanf("%d",&nizC[i][j]);

	
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			i_pomoc=i;
			j_pomoc=j;
			
			tempB=nizB[i_pomoc][j_pomoc];
		
			for (i=0; i < visina; i++){
				for (j=0; j < sirina; j++){
					if (nizB[i][j]==tempB)
					tempB_br++;
				}
			}
			
			tempC=nizC[i_pomoc][j_pomoc];
			
			for (i=0; i < visina; i++){
				for (j=0; j < sirina; j++){
					if (nizC[i][j]==tempC)
					tempC_br++;
				}
			}
			
			
			for (i = 0; i < visina; i++){
				for (j=0; j < sirina; j++){
					if (nizA[i][j]==tempB)
					tempAB_br++;
					if (nizA[i][j]==tempC)
					tempAC_br++;
				}
			}
			
			if((tempB_br!=tempAB_br)||(tempC_br!=tempAC_br))
			{
				printf("NE");
				return 1;
			}
			
			tempB_br=0;
			tempC_br=0;
			tempAB_br=0;
			tempAC_br=0;
			j=j_pomoc;
			i=i_pomoc;
		}
	}

	printf("DA");
	
	return 0;
}
