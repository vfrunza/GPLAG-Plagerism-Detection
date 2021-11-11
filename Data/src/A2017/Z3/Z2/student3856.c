#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void zaokruzi1(float niz[],int vel)
{
	int i;
	for(i=0; i<vel; i++) {
		niz[i]=round(niz[i]*10)/10;
	}
}
void preslozi(float niz[],int vel,int k)
{
	zaokruzi1(niz,vel);
	int i,suma=0,broj,br=0;
	float noviniz[100];

	for(i=0; i<vel; i++) {
		suma=0;
		if(fabs(niz[i])-abs((int)niz[i])>0.0000001)
			broj=(int)(abs(niz[i]*10));
		else broj=(int)(abs(niz[i]));
		while(broj!=0) {
			suma+=broj%10;
			broj=broj/10;
		}
		if(suma>=k) {
			noviniz[br]=niz[i];
			br++;
		}
	}
	while(br<vel) {
		for(i=0; i<vel; i++) {
			suma=0;
			if(fabs(niz[i])-abs((int)niz[i])>0.000001)
				broj=(int)(abs(niz[i]*10));
			else broj=(int)(abs(niz[i]));
			while(broj!=0) {
				suma+=broj%10;
				broj=broj/10;
			}
			if(suma<k) {
				noviniz[br]=niz[i];
				br++;
			}
		}
	}
	for(i=0; i<vel; i++) {

		niz[i]=noviniz[i];

	}
}

int main()
{


	return 0;
}
//nadijina verzija
#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz, int vel)
{
	float *p = niz;
	while(p < niz+vel) {
		*p = round(*p*10)/10;
		p++;
	}
}
//suma cifara
int prebroji(float x)
{
	int s, suma = 0;
	x = fabs(x);
	//round jer je s tipa int, a x tipa float
	s = round(x*10);

	while(s) {
		suma += s%10;
		s /=10;

	}

	return suma;
}
//preslazemo clanove niza uz ocuvanje poretka ako je ispunjen trazeni uslov,bez upotrebe pomocnog niza
//gledamo desni clan niza,on treba da zadovoljava uslov,a trenutni clan ne treba i onda ih mijenjamo
void preslozi(float* p, int vel, int k)
{
	zaokruzi1(p,vel);
	int i,j;
	float temp;
	for(i = 0; i < vel; i++) {
		for(j = 0; j < vel-1; j++) {
			//poredimo parove, kao kod bubble sorta, te ako je suma cifara desnog clana veca od sume lijevog, zamjenimo im mjesta
			if(prebroji(p[j+1]) >= k && prebroji(p[j]) < k) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

}

int main()
{
	return 0;
}
