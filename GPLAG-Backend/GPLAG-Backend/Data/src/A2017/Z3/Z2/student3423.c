#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz,int duzina){
	
	int i,temp=0;
	for( i=0; i<duzina; i++) {
		*niz=(*niz)*10.0f;

		*niz=round(*niz);

		*niz/=10;
		niz++;
	}



}

int sume (float broj) {

		int sumabr=0;
		int temp=0;
		temp = fabs(broj*10);


		while (temp>0) {
		sumabr+=(temp%10);
		temp=temp/10;
		}
	return sumabr;
}


void preslozi(float niz[], int duzina, int k){
	zaokruzi1(niz,duzina);

	int i,j;
	float temp;

	for (i=0; i<duzina; i++) {

		if(sume(niz[i]) < k) {
			temp = niz[i];
			for(j = i; j < duzina - 1; j++) {
				niz[j] = niz[j+1];
			}
			niz[duzina-1] = temp;

		}
	}
}

int main()
{

	return 0;
}
