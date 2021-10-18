#include<stdio.h>
#include<math.h>
void zaokruzi1 (float *pok, int vel_niza) {
	int i;
	for(i=0; i<vel_niza; i++) {
		*pok*=10;
		*pok=round(*pok);
		*pok/=10;
		pok++;
	}

}
void preslozi (float *p, int vel_niza, int k) {
	int i,j=0,cifre1,pomocni[100],vel,tmp,c,m,e,preskoci;
	float pomjeranje_br[100],pomjeranje_c[100],pomocna1,pomocna2;
	zaokruzi1(p,vel_niza);
	for(i=0; i<vel_niza; i++) {
		cifre1=0;
		if(p[i]!=(int)p[i]) tmp=10*p[i];
		else tmp=p[i];
		if(tmp<0) tmp*=-1;
		while(tmp!=0) {
		    c=tmp%10;
			cifre1+=c;
			tmp/=10;
		}
		pomocni[j]=cifre1;
		j++;
	}
	for(i=0; i<vel_niza; i++) {
		m=-1;
		preskoci=0;
		if(pomocni[i]>=k) {
			for(j=0; j<i; j++) { 
				if(pomocni[j]<k) { 
					m=j;
					break;
				}
				else preskoci++;
			}
		}
		if(m!=-1) {
			vel=i+1;
			for(e=preskoci; e<vel; e++) {
				pomjeranje_br[e]=p[e];
				pomjeranje_c[e]=pomocni[e];
			}
			pomocna1=pomjeranje_br[vel-1],pomocna2=pomjeranje_c[vel-1];
			for(e=preskoci; e<vel; e++) { 
				if(e==preskoci) {
					p[e]=pomocna1;
					pomocni[e]=pomocna2;
				} else {
					p[e]=pomjeranje_br[e-1];
					pomocni[e]=pomjeranje_c[e-1];
				}
			}
		}
	}
}
int main() {
	int i,broj;
	float brojevi[6];
	printf("Unesi elemente niza: ");
	for(i=0;i<6;i++) {
		scanf("%f",&brojevi[i]);
	}
	printf("Unesi broj k: ");
	scanf("%d",&broj);
	zaokruzi1(brojevi,6);
	preslozi(brojevi,6,broj);
	printf("Nakon preslaganja niz je: ");
	for(i=0;i<6;i++) printf("%g ",brojevi[i]);
	return 0;
}
