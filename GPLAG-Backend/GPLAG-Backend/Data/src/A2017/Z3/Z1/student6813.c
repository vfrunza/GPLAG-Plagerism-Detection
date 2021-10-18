#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int i, j, k, l,br=0,b;
	
	
	for (i=0; i<vel1; i++) {
		for (j=0; j<i; j++) {
			if (niz1[i]==niz1[j] && i!=j ) {
				break;
			}
		}
		if(i==j) {


			b=0;
			for (k=0; k<vel2; k++) {
				if (niz1[i]==niz2[k]) {
					for (l=0; l<vel3; l++)
						if (niz2[k]!=niz3[l]) {
							b++;
						}
						else {
							break;
						}
					if (b==vel3) {
						br++;
						break;
					}

				}
			}
		}

	}

	for (i=0; i<vel2; i++) {

		for (j=0; j<i; j++) {
			if (niz2[i]==niz2[j] && i!=j) {
				break;
			}
		}
		if(i==j) {

				b=0;
			for (k=0; k<vel3; k++) {
				if (niz2[i]==niz3[k]) {
					for (l=0; l<vel1; l++)
						if (niz3[k]!=niz1[l]){
							b++;
						}
						else {
							break;
						}
					if (b==vel1) {
						br++;
						break;
					}

				}
			}
		}

	}


	for (i=0; i<vel3; i++) {

		for (j=0; j<i; j++) {
			if (niz3[i]==niz3[j] && i!=j) {
				break;
			}
		} if(i==j){
		 

b=0;
			for (k=0; k<vel1; k++) {
				if (niz3[i]==niz1[k]) {
					for (l=0; l<vel2; l++)
						if (niz1[k]!=niz2[l]){ 
						b++;
						}
						else {
							break;
						}
					if (b==vel2) {
						br++;
						break;
					}

				}
			}
		}

	}
	return br;
}


int main()
{
	int niz1[]= {1,2,3,5},niz2[]= {1,2,4,6,7},niz3[]= {1,3,4,8,9,10};
	printf("%d",dva_od_tri(niz1,4,niz2,5,niz3,6));

	return 0;
}