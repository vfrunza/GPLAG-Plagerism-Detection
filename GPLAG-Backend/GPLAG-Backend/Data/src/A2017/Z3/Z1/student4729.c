#include <stdio.h>
int dva_od_tri (int nizA[], int velA, int nizB[], int velB, int nizC[], int velC){
	int* p= &nizA;
	int* q= &nizB;
	int* z= &nizC;
	int i,j,k;
	int brojac;
	for (i=0; i<velA;i++){
		for (j=0; j<velB; j++){
			for (k=0; k<velC; k++){
			if (*p==*q || *q==*z || *p==*z)
			brojac++;
		}}}
	return brojac;
}
int main(void) {
	int vela,velb,velc;
	int b,t,s;
	int niza[100],nizb[100],nizc[100];
	int rez;
	scanf ("%d %d %d",&vela, &velb, &velc);
	scanf ("\n%d ", &niza[vela]);
	scanf ("\n%d ", &nizb[velb]);
	scanf ("%d ", &nizc[velc]);

	for (b=0; b<vela; b++){
		for (t=0; t<velb; t++){
			for (s=0; s<velc; s++){
				rez=dva_od_tri (niza,vela,nizb,velb,nizc,velc);
			}}}
			printf ("%d", rez);
	return 0;
}
