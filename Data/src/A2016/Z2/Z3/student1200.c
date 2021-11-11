#include <stdio.h>

int main()
{
	int mat[20][20]= {{0}};
	int i,j,broj,tacka1,tacka2;
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d",&broj);
		if(broj<=0 || broj>10)
			printf("Pogresan unos\n");
	} while(broj<=0 || broj>10);
	for(i=0; i<broj; i++) {
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&tacka1,&tacka2);
		if(tacka1<0 || tacka1>=20 || tacka2<0 || tacka2>=20) {
			printf("Pogresan unos\n");
			i--;
		} else mat[tacka1][tacka2]=1;
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(mat[j][i]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}




	return 0;
}
