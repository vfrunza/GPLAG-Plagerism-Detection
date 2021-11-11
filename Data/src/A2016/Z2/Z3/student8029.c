#include <stdio.h>

int main() {
	int nizx[20], nizy[20];
	char mat[20][20];
	int i, j, k, brtacaka;
	
	do { 
		printf("Unesite broj tacaka: ");
		scanf("%d", &brtacaka);
		if(brtacaka <= 0 || brtacaka >10) printf("Pogresan unos\n");
	} while (brtacaka <= 0 || brtacaka >10);
		
	for(i=0; i<brtacaka; i++)
	{ 	
		do {
			printf("Unesite %d. tacku: ",(i+1));
			scanf("%d %d", &nizx[i] , &nizy[i]);
			if(nizy[i] >=20 || nizy[i]<0 || nizx[i] >=20 || nizx[i]<0 ) printf("Pogresan unos\n");
		} while (nizy[i] >=20 || nizy[i]<0 || nizx[i] >=20 || nizx[i]<0 );
	}
		
	for(i=0; i<20; i++)
		for(j=0; j<20; j++)
			mat[i][j] = ' ';
	
	for(i=0; i<20; i++)
		for(j=0; j<20; j++)
			for(k=0; k<brtacaka; k++)
				mat[nizx[k]][nizy[k]] = '*';
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
			printf("%c", mat[j][i]);
		printf("\n");
	}
		
	return 0;
}
