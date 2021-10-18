#include <stdio.h>
int jedan_od_dva(int *niza,int vela,int broj)
{
	int *p=niza;
	int jel=0;
	while(p<niza+vela) {
		if(*p==broj) jel=1;
		p++;
	}
	p=niza;
	return jel;
}
void novi_niz(int niz[],int vel,int niz2[])
{
	int *p=niz;
	int *q=niz2;
	while(p<niz+vel) {
		*q=*p;
		p++;
		q++;
	}
}
int dva_od_tri(int *niz1,int vel1,int *niz2,int vel2,int *niz3, int vel3)
{
	int *p1;
	int *p2;
	int *p3;
	int  br=0,br1=0,kol=0,i=0,k=0,j=0,pvel1=vel1,pvel2=vel2,pvel3=vel3;
	int pniz1[1000]= {0},pniz2[1000]= {0},pniz3[1000]= {0};
	novi_niz(niz1,vel1,pniz1);
	novi_niz(niz2,vel2,pniz2);
	novi_niz(niz3,vel3,pniz3);
	if (vel1==0 && vel2==0 && vel3==0) return kol;
	for(i=0; i<pvel1; i++) {
		for(j=i+1; j<pvel1; j++) {
			if(pniz1[i]==pniz1[j]) {
				for(k=j; k<pvel1-1; k++) {
					pniz1[k]=pniz1[k+1];
				}
				pvel1--;

				j--;
			}
		}
	}
	for(i=0; i<pvel2; i++) {
		for(j=i+1; j<pvel2; j++) {
			if(pniz2[i]==pniz2[j]) {
				for(k=j; k<pvel2-1; k++) {
					pniz2[k]=pniz2[k+1];
				}
				pvel2--;

				j--;
			}
		}
	}
	for(i=0; i<pvel3; i++) {
		for(j=i+1; j<pvel3; j++) {
			if(pniz3[i]==pniz3[j]) {
				for(k=j; k<pvel3-1; k++) {
					pniz3[k]=pniz3[k+1];
				}
				pvel3--;

				j--;
			}
		}
	}
	p1=pniz1;
	p2=pniz2;
	p3=pniz3;
	if(pvel1==0 && pvel2!=0 && pvel3!=0) {
		while(p2<pniz2+pvel2) {
			br=jedan_od_dva(pniz3,pvel3,*p2);
			if(br) kol++;
			p2++;
		}
	}
	p2=pniz2;
	if(pvel1!=0 && pvel2==0 && pvel3!=0) {
		while(p1<pniz1+pvel1) {
			br=jedan_od_dva(pniz3,pvel3,*p1);
			if(br) kol++;
			p1++;
		}
	}
	p1=pniz1;
	if(pvel1!=0 && pvel2!=0 && pvel3==0) {
		while(p1<pniz1+pvel1) {
			br=jedan_od_dva(pniz2,pvel2,*p1);
			if(br) kol++;
			p1++;
		}
	}
	p1=pniz1;
	if(pvel1!=0 && pvel2!=0 && pvel3!=0) {
		while(p1<pniz1+pvel1) {
			br=jedan_od_dva(pniz2,pvel2,*p1);
			br1=jedan_od_dva(pniz3,pvel3,*p1);
			if((br==1 && br1==0) || (br==0 && br1==1)) kol++;
			p1++;
		}
		p3=pniz3;
		while(p3<pniz3+pvel3) {
			br=jedan_od_dva(pniz2,pvel2,*p3);
			br1=jedan_od_dva(pniz1,pvel1,*p3);
			if(br==1 && br1==0) kol++;
			p3++;
		}
	}
	return kol;
}


int main()
{
	printf("Zadatak 1, zadaca 3 ");
	return 0;
}
