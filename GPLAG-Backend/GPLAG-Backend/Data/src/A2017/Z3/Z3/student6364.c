#include <stdio.h>
// definisemo tip bool, a prima varijable false i true
typedef enum { false, true } bool;

int izbaci_cifre(int brojevi[], int nB, int cifre[], int nC)
{
	int i, j, broj, k, t, f, sgn;
	bool found;
	for(f=0; f<nC; f++) if(cifre[f]<0 || cifre[f]>9) return 0;
	for(i=0; i<nB; i++) {
		int temp[20];
		// sgn- predznak
		sgn=1; 
		// ako je bio negativan pretvaramo u poz
		broj=brojevi[i];
		if(broj<0) {
			sgn=-1;
			broj*=sgn;
		}
		for(j=0; broj!=0; broj/=10) {
			temp[j++]=broj%10;
			if(temp[j-1]<0)	return 0;
			found=false;
			// provjeramo da li se dva puta ponovila, dok uporedjuje sa ciframa
			for(f=0; f<nC; f++)	if(temp[j-1]==cifre[f]) {
					if(found) return 0;
					found = true;
				}
				// ako je nasao jednom, brise
			if(found) temp[j-1]=-1;
		}
		// 125457
		// 1 2 5 4 5 7
		// -1 2 5 4 5 7
		// sastavlja broj
		t=1;
		broj=0;
		for(k=0; k<j; k++) if(temp[k]!=-1) {
				broj+=temp[k]*t;
				t*=10;
			}
		brojevi[i]=broj*sgn;
	}
	return 1;
}
int main()
{

	return 0;
}
