#include <stdio.h>


int main() {
	int i=0,j=0,k=0,l=0,m=0;
	float postotak;
	int ukvoz;
	char vozilo;
	printf("Unesite vozila: ");
	do {
	scanf("%c",&vozilo);
	
	if (vozilo=='c' || vozilo=='C')
	i++;
	else if (vozilo=='b' || vozilo=='B')
	j++;
	else if (vozilo=='s' || vozilo=='S')
	k++;
	else if (vozilo=='v' || vozilo=='V')
	l++;
	else if (vozilo=='p' || vozilo=='P')
	m++;
	else if (vozilo=='k' || vozilo=='K')
	break;
	else printf("Neispravan unos\n");
	}
	while (1);
	

ukvoz=i+j+k+l+m;
printf("Ukupno evidentirano %d vozila.\n",ukvoz);

if (ukvoz==0){
	printf("Najpopularnija boja je crna (0.00%%). "); return 0;
}

if (i>=j && i>=k && i>=l && i>=m){
	 postotak = (i*100.) / ukvoz;
	printf("Najpopularnija boja je crna (%.2f%%).",postotak); return 0;}
if (j>=i && j>=k && j>=l && j>=m){
	 postotak = (j*100.) / ukvoz;
	printf("Najpopularnija boja je bijela (%.2f%%).",postotak); return 0;}
if (k>=i && k>=j && k>=l && k>=m){
	 postotak = (k*100.) / ukvoz;
	printf("Najpopularnija boja je siva (%.2f%%).",postotak); return 0;}
if (l>=i && l>=j && l>=k && l>=m){
      postotak = (l*100.) / ukvoz;
	printf("Najpopularnija boja je crvena (%.2f%%).",postotak); return 0;}
if (m>=i && m>=j && m>=k && m>=l){
	 postotak = (m*100.) / ukvoz;
	printf("Najpopularnija boja je plava (%.2f%%).",postotak); return 0;}
	
	return 0;
}
