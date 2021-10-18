#include <stdio.h>
#include <math.h>
float *zaokruzi1(float *niz,int vel)
{
	float *p=niz;
	if (vel==0) return 0;
	while (p<niz+vel) {
		*p *=10;
		if (*p>0) *p=(int) (*p+0.5);
		else if (*p<0) *p=(int) (*p-0.5);
		*p++/=10;
	}
	return niz;
}
void zamijeni (float *p1, float *p2){
	float temp=*p1;
	*p1=*p2;
	*p2=temp;
}
void preslozi(float *niz,int vel,int k)
{
	int i,j,brojac=0,c[1000],m,novi_niz[100];
	zaokruzi1(niz,vel);
	for (i=0; i<vel; i++) {
		while (niz[i]>0) {
			novi_niz[i]=(int) (niz[i]*10);
			c[i]+=novi_niz[i]%10;
			novi_niz[i]/=10;
		}
	}
	for (i=0; i<vel; i++) {
			for (j=i+1; j<vel; j++) {
				if (c[i]>=k) {
					for (m=j; m>brojac; m--) {
						zamijeni(&niz[m],&niz[m+1]);
					}
					brojac++;
				}
				else {
					zamijeni(&niz[j-1],&niz[j]);
				}
			}
		}

}
int main() {
	int i,vel,k;
	float niz[100];
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	printf("Unesite clanove niza: ");
	for (i=0;i<vel;i++)
	{
		scanf("%f",&niz[i]);
	}
	zaokruzi1(niz,vel);
	printf("Unesite prirodan broj k: ");
	scanf("%d",&k);
	preslozi(niz,vel,k);
	printf("Niz glasi: ");
	for (i=0;i<vel;i++)
	{
		printf("%g ",niz[i]);
	}
	return 0;
}
