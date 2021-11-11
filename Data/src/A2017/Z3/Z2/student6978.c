#include <stdio.h>
#include<math.h>
void zaokruzi1(float* niz, int velicina)
{
	int i;
	for (i=0; i<velicina; i++) {
		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]=niz[i]/10;
	}
}
void preslozi (float* niz, int velicina, int limit_suma)
{
	int i,cijeli_dio=0,ostatak=0,pocetak=0,j,suma=0,cijeli_dio_temp;
	float temp;
	zaokruzi1(niz,velicina);
	for (i=0; i<velicina; i++) {
		cijeli_dio=niz[i];
		ostatak=(niz[i]-cijeli_dio)*10;
		if (cijeli_dio<10) {
			if (fabs(cijeli_dio)+fabs(ostatak)>=limit_suma) {
				for(j=i; j>pocetak; j--) {
					temp=niz[j-1];
					niz[j-1]=niz[j];
					niz[j]=temp;

				}
				pocetak++;
			}

		} else {
			cijeli_dio_temp=fabs(cijeli_dio);
			suma+=cijeli_dio_temp%10;
			while (cijeli_dio_temp!=0) {

				cijeli_dio_temp=cijeli_dio_temp/10;
				suma+=cijeli_dio_temp%10;
			}
			if (suma+fabs(ostatak)>=limit_suma) {
				for(j=i; j>pocetak; j--) {
					temp=niz[j-1];
					niz[j-1]=niz[j];
					niz[j]=temp;

				}
				pocetak++;
			}

		}
	}
}
int main()
{
	float niz[100];
	int vel,i,k;
	scanf("%d",&vel);
	for (i=0; i<vel; i++)
		scanf("%f",&niz[i]);
	zaokruzi1(niz,vel);
	for (i=0; i<vel; i++)
		printf("%f ",niz[i]);
	printf("Unesite k");
	scanf("%d",&k);

	return 0;
}
