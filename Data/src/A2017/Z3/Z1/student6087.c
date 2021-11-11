#include <stdio.h>

int dva_od_tri(int* niz, int vel1, int* niz2, int vel2, int* niz3, int vel3)
{
	int i,j,k,a,brojac=0;
	for(i=1; i<=vel1; i++) {
		if (niz[i] == niz[i-1]) continue;
		for (j=0; j<vel2; j++) {
			if(niz[i] == niz2[j]) {
				brojac++;
				a = niz[i];
				for(k=0; k<vel3; k++) {
					if(a == niz3[k])
					brojac--; break;
				} break;
			}
		}
	} 
	for(i=1; i<=vel1; i++) {
		if (niz[i] == niz[i-1]) continue;
		for (j=0; j<vel3; j++) {
			if(niz[i] == niz3[j]) {
				brojac++;
				a = niz[i];
				for(k=0; k<vel2; k++) {
					if(a == niz2[k])
					brojac--; break;
				} break;
			}
		}
	} 
	for(i=1; i<=vel2; i++) {
		if (niz2[i] == niz2[i-1]) continue;
		for (j=0; j<vel3; j++) {
			if(niz2[i-1] == niz3[j]) {
				brojac++;
				a = niz2[i];
				for(k=0; k<vel1; k++) {
					if(a == niz[k])
					brojac--; break;
				} break;
			}
		}
	} return brojac;
}	

int main()
{
	int i,a[100],b[100],c[100],n1,n2,n3;
	printf("Unesite velicine nizova: ");
	scanf("%d %d %d", &n1, &n2, &n3);

	printf("Unesite niz 1: ");
	for (i=0; i<n1; i++) {
		scanf("%d", &a[i]);
	}
	printf("Unesite niz 2: ");
	for (i=0; i<n2; i++) {
		scanf("%d", &b[i]);
	}
	printf("Unesite niz 3: ");
	for (i=0; i<n3; i++) {
		scanf("%d", &c[i]);
	}
	dva_od_tri(a,n1,b,n2,c,n3);


	return 0;
}
