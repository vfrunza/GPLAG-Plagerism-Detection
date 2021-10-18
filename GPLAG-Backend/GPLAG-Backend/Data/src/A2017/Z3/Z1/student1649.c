#include <stdio.h>

int dva_od_tri (int niz1[], int brc1, int niz2[], int brc2, int niz3[], int brc3)
{
	int i,j,k;
	int niz_1[30];
	int niz_2[30];
	int niz_3[30];
	int promijeni=0;
	int brojac1_2=0,brojac1_3=0,brojac2_3=0;
	int temp=0,brojac=0;


	for(i=0; i<brc1; i++) niz_1[i]=niz1[i];
	for(i=0; i<brc2; i++) niz_2[i]=niz2[i];
	for(i=0; i<brc3; i++) niz_3[i]=niz3[i];

	for(i=0; i<brc1; i++) {
		for(j=0; j<brc1; j++) {
			if(i!=j) {
				if(niz_1[i]==niz_1[j]) {
					promijeni=niz_1[j];
					niz_1[j]=niz_1[brc1-1];
					niz_1[brc1-1]=promijeni;
					brc1--;
					j--;
				}
			}
		}
	}

	for(i=0; i<brc2; i++) {
		for(j=0; j<brc2; j++) {
			if(i!=j) {
				if(niz_2[i]==niz_2[j]) {
					promijeni=niz_2[j];
					niz_2[j]=niz_2[brc2-1];
					niz_2[brc2-1]=promijeni;
					brc2--;
					j--;
				}
			}
		}
	}

	for(i=0; i<brc3; i++) {
		for(j=0; j<brc3; j++) {
			if(i!=j) {
				if(niz_3[i]==niz_3[j]) {
					promijeni=niz_3[j];
					niz_3[j]=niz_3[brc3-1];
					niz_3[brc3-1]=promijeni;
					brc3--;
					j--;
				}
			}
		}
	}

	for(i=0; i<brc1; i++) {
		for(j=0; j<brc2; j++) {
			if(niz_1[i]==niz_2[j]) {
				temp=niz_1[i];

				for(k=0; k<brc3; k++) {
					brojac1_3=0;
					if(niz_3[k]==temp) {
						brojac1_3=1;
						break;
					}
				}
				if(brojac1_3==0) {
					brojac=brojac+1;
				}



			}
		}
	}





	for(i=0; i<brc1; i++) {
		for(j=0; j<brc3; j++) {
			if(niz_1[i]==niz_3[j]) {
				temp=niz_1[i];

				for(k=0; k<brc2; k++) {
					brojac1_2=0;
					if(niz_2[k]==temp) {
						brojac1_2=1;
						break;
					}
				}
				if(brojac1_2==0) {
					brojac=brojac+1;
				}



			}
		}
	}

	for(i=0; i<brc2; i++) {
		for(j=0; j<brc3; j++) {
			if(niz_2[i]==niz_3[j]) {
				temp=niz_2[i];

				for(k=0; k<brc1; k++) {
					brojac2_3=0;
					if(niz_1[k]==temp) {
						brojac2_3=1;
						break;
					}
				}
				if(brojac2_3==0) {
					brojac=brojac+1;
				}

			}
		}
	}


	return brojac;
}



int main()
{

	int niz1[30],niz2[30],niz3[30];
	int brc1,brc2,brc3;
	int i;
	printf("Unesite velicine nizova:");
	scanf("%d%d%d",&brc1,&brc2,&brc3);

	printf("\nUnesite clanove prvog niza");


	for(i=0; i<brc1; i++) {
		scanf("%d",&niz1[i]);
	}

	printf("\nUnesite clanove drugog niza");


	for(i=0; i<brc2; i++) {
		scanf("%d",&niz2[i]);
	}


	printf("\nUnesite clanove treceg niza");


	for(i=0; i<brc3; i++) {
		scanf("%d",&niz3[i]);
	}



	printf("Funkcija vraca broj %d",dva_od_tri(niz1,brc1,niz2,brc2,niz3,brc3));



	return 0;
}
