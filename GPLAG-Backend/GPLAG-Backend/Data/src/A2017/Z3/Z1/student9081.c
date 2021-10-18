#include <stdio.h>
int dva_od_tri (int nizA[],int vel1,int nizB[],int vel2,int nizC[],int vel3)
{
	int i,j,k,l,brojacABC=0,brojacAB=0,brojacAC=0,brojacBC=0,duplikatA=0,duplikatB=0,duplikatC=0;
	/*U narednoj petlji trazimo zajednicke elemente prvog i drugog niza,zanemarujuci duplikate*/
	for (i=0; i<vel1; i++) {
		for (j=i+1; j<vel1; j++) {
			if (nizA[i]==nizA[j]) {
				duplikatA=1;
				break;
			}
		}
		if (duplikatA==0) {
			for (j=0; j<vel2; j++) {
				for (k=j+1; k<vel2; k++) {
					if (nizB[j]==nizB[k]) {
						duplikatB=1;
						break;
					}
				}
				if (duplikatB==0 && nizA[i]==nizB[j])
					brojacAB++;
				duplikatB=0;
			}
		}
		duplikatA=0;
	}
	/*Analogno trazimo zajednicke elemente prvog i treceg niza, te drugog i treceg niza,opet bez ponavljanja elemenata*/
	duplikatA=0;
	duplikatB=0;
	duplikatC=0;
	for (i=0; i<vel1; i++) {
		for (j=i+1; j<vel1; j++) {
			if (nizA[i]==nizA[j]) {
				duplikatA=1;
				break;
			}
		}
		if (duplikatA==0) {
			for (j=0; j<vel3; j++) {
				for (k=j+1; k<vel3; k++) {
					if (nizC[j]==nizC[k]) {
						duplikatC=1;
						break;
					}
				}
				if (duplikatC==0 && nizA[i]==nizC[j])
					brojacAC++;
				duplikatC=0;
			}
		}
		duplikatA=0;
	}
	duplikatA=0;
	duplikatB=0;
	duplikatC=0;
	for (i=0; i<vel2; i++) {
		for (j=i+1; j<vel2; j++) {
			if (nizB[i]==nizB[j]) {
				duplikatB=1;
				break;
			}
		}
		if (duplikatB==0) {
			for (j=0; j<vel3; j++) {
				for (k=j+1; k<vel3; k++) {
					if (nizC[j]==nizC[k]) {
						duplikatC=1;
						break;
					}
				}
				if (duplikatC==0 && nizB[i]==nizC[j])
					brojacBC++;
				duplikatC=0;
			}
		}
		duplikatB=0;
	}
	duplikatA=0;
	duplikatB=0;
	duplikatC=0;
	/*Trazimo zajednicke elemente sva tri niza,bez ponavljanja*/
	for (i=0; i<vel1; i++) {
		for (j=i+1; j<vel1; j++) {
			if (nizA[i]==nizA[j]) {
				duplikatA=1;
				break;
			}
		}
		if (duplikatA==0) {
			for (j=0; j<vel2; j++) {
				for (k=j+1; k<vel2; k++) {
					if (nizB[j]==nizB[k]) {
						duplikatB=1;
						break;
					}
				}
				if (duplikatB==0 && nizA[i]==nizB[j]) {
					for (k=0; k<vel3; k++) {
						for (l=k+1; l<vel3; l++) {
							if (nizC[k]==nizC[l]) {
								duplikatC=1;
								break;
							}
						}
						if (duplikatC==0 && nizB[j]==nizC[k])
							brojacABC++;
						duplikatC=0;
					}
				}
				duplikatB=0;

			}
		}
		duplikatA=0;
	}
	/*Ako nizove posmatramo kao skupove,na osnovu Venovih dijagrama,elementi koji se javljaju u dva od tri niza su dati izrazom ispod*/
	return brojacAB+brojacAC+brojacBC-3*brojacABC;
}
int main()
{
	int i,vel1,vel2,vel3,nizA[100],nizB[100],nizC[100];
	printf ("Unesite tri dimenzije: ");
	scanf ("%d %d %d",&vel1,&vel2,&vel3);
	printf ("Unesite niz: ");
	for (i=0; i<vel1; i++)
		scanf ("%d",&nizA[i]);
	printf ("Unesite niz: ");
	for (i=0; i<vel2; i++)
		scanf ("%d",&nizB[i]);
	printf ("Unesite niz: ");
	for (i=0; i<vel3; i++)
		scanf ("%d",&nizC[i]);
	printf ("Broj elemenata koji se javlja u dva od tri niza je %d.",dva_od_tri(nizA,vel1,nizB,vel2,nizC,vel3));
	return 0;
}
