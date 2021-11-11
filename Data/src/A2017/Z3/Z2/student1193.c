#include <stdio.h>
#include <math.h>
void zaokruzi1 (double *niz, int vel)
{
	int i;
	for(i=0; i<vel; i++) {
		*niz=round(*niz*10)/10;
		niz++;
	}

}
void preslozi(float *niz, int vel, int k)
{
	zaokruzi1(niz,vel);
	int i,temp;
	float niz1[],niz2[];
	for(i=0; i<vel; i++) {
		temp=abs(niz[i]*10);
		while(temp>0) {
			suma+=temp%10;
			temp=temp/10;
		}
		if(suma>k) {
		
	}

	}





}

int main()
{
	int i,vel,k;
	float niz[100];
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	printf("Unesite elemente niza: ");
	for(i=0; i<vel; i++) {
		scanf("%f",&niz[i]);
	}
	printf("Unesite k: ");
	scanf("%d",&k);


	return 0;
}
