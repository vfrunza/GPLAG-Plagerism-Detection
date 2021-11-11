#include <stdio.h>
#define PI 3.1415926

int main() {
	float niz[500];
	int i, n, mi, stepeni, se, j;
	float a=0;
	char predznak=' ';
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%f", &niz[i]);
	}
	printf("Uglovi su: ");
	for(i=0; i<n; i++) {
			predznak=' ';
		a=niz[i]*(180./PI);
			if(a<0) {
			a*=-1;
			predznak='-';
		}
		stepeni=(int)a;
		mi=(int)(((a-stepeni)*3600)+0.5)/60;
		if (mi==60) {
			mi=0;
			stepeni+=1;
		}
		se=(int)(((a-stepeni)*3600)+0.5)%60;
		if(se>=31)
		{
			for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			}
				n--;
				i--;
		}
		if(se<=30 && predznak!='-') printf("\n%d stepeni %d minuta %d sekundi", stepeni, mi, se);
		else if(se<=30 && predznak=='-') printf("\n-%d stepeni %d minuta %d sekundi", stepeni, mi, se);
	}
	return 0;
}

