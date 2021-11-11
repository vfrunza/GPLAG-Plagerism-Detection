#include <stdio.h>
#include <math.h>
int dva_od_tri(int *nizPrvi, int velicina1, int *nizDrugi, int velicina2, int *nizTreci,  int velicina3)
{
	int nizBrojacaPrvi[100]={0}, nizBrojacaDrugi[100]={0}, nizBrojacaTreci[100]={0}, nizBrojacaPrviNeg[100]={0},
	nizBrojacaDrugiNeg[100]={0},nizBrojacaTreciNeg[100]={0}, brojacGlavni=0, i, k;
	
	for (i = 0; i < velicina1; i++) {
		
		if (*(nizPrvi+i) < 0) {
			k=fabs(*(nizPrvi+i));
			nizBrojacaPrviNeg[k]=1;
		}
		
		else nizBrojacaPrvi[*(nizPrvi+i)]=1;
	}
	
	
	for (i = 0; i < velicina2; i++) {
		if (*(nizDrugi+i) < 0) {
			
			k=fabs(*(nizDrugi+i));
			nizBrojacaDrugiNeg[k]=1;
		}
		else nizBrojacaDrugi[*(nizDrugi+i)]=1;
	}
	
	
	for (i = 0; i < velicina3; i++) {
		if (*(nizTreci+i) < 0) {
			
			k=fabs(*(nizTreci+i));
			nizBrojacaTreciNeg[k]=1;
		}
		else nizBrojacaTreci[*(nizTreci+i)]=1;
	}
	
	for (i = 0; i < 100; i++) {
		if (nizBrojacaPrvi[i]+nizBrojacaDrugi[i]+nizBrojacaTreci[i]==2)brojacGlavni++;
		if (nizBrojacaPrviNeg[i]+nizBrojacaDrugiNeg[i]+nizBrojacaTreciNeg[i]==2)brojacGlavni++; 
	}
	return brojacGlavni;
}




int main()
{

	int nizPrvi[100], nizDrugi[100], nizTreci[100], velicina1, velicina2, velicina3, i;

	//Prvi niz
	printf("Unesite velicinu prvoga niza: ");
	scanf("%d", &velicina1);

	printf("Unesite clanove prvoga niza: ");

	for (i = 0; i < velicina1; i++) {
		scanf("%d", &nizPrvi[i]);
	}

	//Drugi niz
	printf("Unesite velicinu drugoga niza: ");
	scanf("%d", &velicina2);

	printf("Unesite clanove prvoga niza: ");

	for (i = 0; i < velicina2; i++) {
		scanf("%d", &nizDrugi[i]);
	}

	//Treci niz
	printf("Unesite velicinu treceg niza: ");
	scanf("%d", &velicina3);

	printf("Unesite clanove treceg niza: ");

	for (i = 0; i < velicina3; i++) {
		scanf("%d", &nizTreci[i]);
	}

	printf("%d", dva_od_tri(nizPrvi,velicina1, nizDrugi, velicina2, nizTreci, velicina3));
	return 0;
}
