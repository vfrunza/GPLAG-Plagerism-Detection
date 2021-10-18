#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int n){
	int i;
	for(i=0;i<n;i++){
		niz[i]=round(niz[i]*10)/10;
	}
}

int suma_cifara(float n){ /*FUNKCIJA KOJA RACUNA SUMU CIFARA REALNOG BROJA*/
	if(n<0) n*=-1;	/*AKO JE BROJ NEGATIVAN, PRETVORI NJEGOVU KOPIJU U POZITIVNU ZBOG IZRACUNAVANJA SUME */
	int x=n*10,suma=0;
	
	while(x!=0){
		suma+=(x%10);
		x/=10;
	}
	return suma;
}

void preslozi (float *p,int vel, int k){
	int i;
	float x;
	zaokruzi1(p,vel);
	for(i=0;i<vel;i++){
		if(suma_cifara(p[i])>=k){	/* PROVJERAVAMO DA LI JE BROJ NA i-TOM MJESTU VECI ILI JEDNAK OD K */
			while(1){					/* PETLJA KOJA POMIJERA BROJ KOJI JE VECI ILI JEDNAK OD K DO PRVOG SLJEDECEG KOJI JE VECI ILI JEDNAK OD K */
				if((i-1)<0) break;	/* SIGURNOST OD IZLAZKA IZVAN OPSEGA */
				if(suma_cifara(p[i-1])<k ){
					x=p[i];
					p[i]=p[i-1];
					p[i-1]=x;
					i--;
				}
				else break;		/* PETLJA SE PREKIDA KADA SE DODJE ISPRED BROJA KOJI JE VECI ILI JEDNAK OD K */
			}
		}
   
	}
}
	
int main() {
	float niz[5];
	int i,k;
	printf ("Unesi niz brojeva: ");
	for(i=0;i<5;i++){
		scanf("%f",&niz[i]);
	}
	printf ("Unesi k: ");
	scanf("%d",&k);
	preslozi(niz,5,k);
	printf ("Nakon poziva funkcije preslozi pri cemu je k=%d niz glasi: ",k);
	for(i=0;i<5;i++){
		printf("%.1f ",niz[i]);
	}
	
	return 0;
}
