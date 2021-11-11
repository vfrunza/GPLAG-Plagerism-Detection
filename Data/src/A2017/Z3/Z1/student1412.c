#include <stdio.h>
//ispitivanje da nema istih clanova u nizu
//u slucaju da je taj clan vec koristen vraca logicku 0
int ISTI(int *niz,int duzina,int i)
{
	int j,LOGICKI=1;;
	if(i!=0) {
		for(j=0; j<duzina; j++) {
			if(*(niz+i)==*(niz+j) && i!=j) {
				LOGICKI=0;
				break;
			} else
				LOGICKI=1;
		}
	}
	return LOGICKI;
}
int dva_od_tri(int *n1,int prvi,int *n2,int drugi,int *n3,int treci)
{
	int i,j,logicki=1,b=0,isti;
	// ispitivanje da li je prvi niz jednak drugom a nije jednak trecem
	for(i=0; i<prvi; i++) {
		//uslov da prvi niz nije jednak trecem
		for(j=0; j<treci; j++) {
			if(*(n1+i)!=*(n3+j))
				logicki=1;
			else {
				logicki=0;
				break;
			}
		}
		isti=ISTI(n1,prvi,i);
		//u slucaju da prvi nije jednak trecem tada se ispituje da li je jednak drugom
		if(logicki==1 && isti!=0) {
			for(j=0; j<drugi; j++) {
				if(*(n1+i)==*(n2+j)) {
					b++;
					break;
				}
			}
		}
	}

	logicki=1;
	// ispitivanje da li je prvi niz jednak trecem a nije jednak drugom
	for(i=0; i<prvi; i++) {
		//ispitivanje nejednakosti prvog niza sa drugim
		for(j=0; j<drugi; j++) {
			if(*(n1+i)!=*(n2+j))
				logicki=1;
			else {
				logicki=0;
				break;
			}
		}
		isti=ISTI(n1,prvi,i);
		// u slucaju nejednakosti sa drugim ispituje se jednakost sa trecim
		if(logicki==1 && isti!=0) {
			for(j=0; j<treci; j++) {
				if(*(n1+i)==*(n3+j)) {
					b++;
					break;
				}
			}
		}
	}
	logicki=1;
	for(i=0; i<drugi; i++) {
		for(j=0; j<prvi; j++) {
			if(*(n2+i)!=*(n1+j))
				logicki=1;
			else {
				logicki=0;
				break;
			}
		}
		isti=ISTI(n2,drugi,i);
		if(logicki==1 && isti!=0) {
			for(j=0; j<treci; j++) {
				if(*(n2+i)==*(n3+j)) {
					b++;
					break;
				}
			}
		}
	}
	return b;
}
int main()
{
	int niz1[]= {0,-1,3};
	int niz2[] = {4, 2, 5};
	int niz3[] = {0, -1};
	printf ("%d ", dva_od_tri(niz1, 3, niz2, 3, niz3, 2));
	return 0;
}
