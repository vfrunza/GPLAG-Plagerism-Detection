#include <stdio.h>

int dva_od_tri (int nizA[],int broj_clanovaA,int nizB[],int broj_clanovaB,int nizC[],int broj_clanovaC)
{
	int i,max_broj=0,brojac_svakog_broja=0,svaki_broj=0,brojac_dva_od_tri=0,ponovljen=0;
	for(i=0;i<broj_clanovaA;i++)
	 if(nizA[i]>max_broj)
	 max_broj=nizA[i];
	for(i=0;i<broj_clanovaB;i++)
	 if(nizB[i]>max_broj)
	 max_broj=nizB[i];
	for(i=0;i<broj_clanovaC;i++)
	 if(nizC[i]>max_broj)
	 max_broj=nizC[i];
	while(svaki_broj<=max_broj)
	{
	 	for(i=0;i<broj_clanovaA;i++)
	 	if(nizA[i]==svaki_broj&&ponovljen==0){ 
	 		brojac_svakog_broja++;
	 		ponovljen=1;
	 	}
	 	ponovljen=0;
	 	for(i=0;i<broj_clanovaB;i++)
	 	if(nizB[i]==svaki_broj&&ponovljen==0) {
	 		brojac_svakog_broja++;
	 			ponovljen=1;
	 	}
	 	ponovljen=0;
	 	for(i=0;i<broj_clanovaC;i++)
	 	if(nizC[i]==svaki_broj&&ponovljen==0) {
	 		brojac_svakog_broja++;
	 			ponovljen=1;
	 	}
	 	ponovljen=0;
	    if(brojac_svakog_broja==2) brojac_dva_od_tri++;
	    svaki_broj++;
	    brojac_svakog_broja=0;
	}
	 return brojac_dva_od_tri;
}
int main() {
	int nizA[100000],nizB[100000],nizC[100000],broj_clanovaA,broj_clanovaB,broj_clanovaC,i;
	printf("Unesi broj clanova prvog niza: ");
	scanf("%d",&broj_clanovaA);
	printf("Unesi clanove prvog niza: ");
	for(i=0;i<broj_clanovaA;i++)
	scanf("%d",&nizA[i]);
	printf("Unesi broj clanova drugog niza: ");
	scanf("%d",&broj_clanovaB);
	printf("Unesi clanove drugog niza: ");
	for(i=0;i<broj_clanovaB;i++)
	scanf("%d",&nizB[i]);
	printf("Unesi broj clanova treceg niza: ");
	scanf("%d",&broj_clanovaC);
	printf("Unesi clanove treceg niza: ");
	for(i=0;i<broj_clanovaC;i++)
	scanf("%d",&nizC[i]);
	printf("%d",dva_od_tri (nizA,broj_clanovaA,nizB,broj_clanovaB,nizC,broj_clanovaC));
	return 0;
}
