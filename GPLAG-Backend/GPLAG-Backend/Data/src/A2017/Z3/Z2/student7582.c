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
