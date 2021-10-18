#include <stdio.h>
int dva_od_tri(int niz1[],int n1,int niz2[], int n2, int niz3[], int n3)
{
	int brojac=0,i=0,j=0, brojaciclanova1[1000]= {0}, brojaciclanova2[1000]= {0},brojaciclanova3[1000]= {0}; 
	/*for petlje koje gledaju koliko puta se ponavlja koji clan u nizu*/
	for(i=0; i<n1; i++) {
		for(j=0; j<1000; j++) {
			if(niz1[i]==j) {
				brojaciclanova1[j]++;
				break;
			}
		}
	}

	for(i=0; i<n2; i++) {
		for(j=0; j<1000; j++) {
			if(niz2[i]==j) {
				brojaciclanova2[j]++;
				break;
			}
		}
	}


	for(i=0; i<n3; i++) {
		for(j=0; j<1000; j++) {
			if(niz3[i]==j) {
				brojaciclanova3[j]++;
				break;
			}
		}
	}

/* for petlja koja provjerava da li se broj ponavlja vise od jedanput i ako da, ostavlja samo jedan takav clan*/  
	for(j=0; j<1000; j++) {

		if(brojaciclanova1[j]>1)
			brojaciclanova1[j]=1;
		if(brojaciclanova2[j]>1)
			brojaciclanova2[j]=1;
		if(brojaciclanova3[j]>1)
			brojaciclanova3[j]=1;
	}
/*ako nam je suma jednaka 2 znaci da se brojevi nalaze u dva od tri niza*/
	for(j=0; j<1000; j++) {

		if((brojaciclanova1[j]+brojaciclanova2[j]+brojaciclanova3[j])==2)
			brojac++;
	}








	return brojac;

}

int main()
{

	return 0;
}