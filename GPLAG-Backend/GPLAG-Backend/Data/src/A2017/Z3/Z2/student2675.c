#include <stdio.h>
#include <math.h>

void zaokruzi1(float *p, int vel_niza)
{
	int i;
	for (i = 0; i < vel_niza; i++)
		*(p+i)=round(*(p+i)*10)/10;
}


void preslozi(float *p, int vel_niza, int k)
{
	zaokruzi1(p,vel_niza);
	float temp_broj;
	int temp, br_cifri, suma, i, j, br_vecih=0;

	for (i = 0; i < vel_niza; i++) {
		suma=0;
		br_cifri=0;
		temp = fabs(*(p+i)*10);
		do {
			br_cifri++;
			temp/=10;
		} while (temp>=1);

		temp = fabs(*(p+i)*10);
		do {
			suma+=temp%10;
			temp/=10;
			br_cifri--;
		} while (br_cifri!=0);

		if (suma>=k) {
			for (j = i; j > 0 + br_vecih; j--) {
				temp_broj=*(p+j-1);
				*(p+j-1)=*(p+j);
				*(p+j)=temp_broj;
			}
			br_vecih++;
		}

	}

}


int main()
{
	int k=8, i;
	float niz[5]= {-1.0, -0.1, -0.2, -4.4, -4.5};

	for (i = 0; i < 5; i++) {
		printf("%7.2f ",niz[i]);
	}
	printf("\n");


	zaokruzi1(niz,5);
	for (i = 0; i < 5; i++) {
		printf("%7g ",niz[i]);
	}
	printf("\n");


	preslozi(niz,5,k);
	for (i = 0; i < 5; i++) {
		printf("%7g ",niz[i]);
	}

	return 0;
}
