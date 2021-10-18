#include <stdio.h>
#include<math.h>
void zaokruzi(float *niz,int vel)
{
	float *p=niz;
	while(p<niz+vel) {
		*p*=10;
		*p=round(*p);
		*p++/=10;
	}
}
int main() {
	int i,vel;
	float niz[100];
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&vel);
	} while(vel<1 || vel>100);
	printf("Unesite elemente niza: ");
	for(i=0;i<vel;i++)
	{
		scanf("%f",&niz[i]);
	}
	zaokruzi(niz, vel);
printf("Niz glasi: ");
for(i=0;i<vel;i++)
{
	printf("%g ", niz[i]);
}
	return 0;
}
