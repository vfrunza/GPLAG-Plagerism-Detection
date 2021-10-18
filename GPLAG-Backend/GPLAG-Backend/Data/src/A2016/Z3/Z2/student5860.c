#include <stdio.h>
#include <math.h>

/* Provjera za Fibonacijev niz. */
int jel(long int x) {
	long int s=sqrt(x);
	return (s*s==x);
}

int provjera(long int n) {
	if(n<=0) {
	   return 0;
	}
	return jel(5*n*n-4) || jel(5*n*n+4);
}

void ubaci(int niz[], int vel) {
	int i, kopija[100], temp, suma=0;
	for(i=0; i<vel; i++) {
		kopija[i]=niz[i];
	}
	for(i=0; i<vel-1; i++) {
		niz[i*2+2]=kopija[i+1];
	}
	for(i=0; i<vel; i++) {
		temp=kopija[i];
		if(temp<0) {
			temp*=-1;
		}
		suma=0;
		while(temp!=0) {
			suma+=temp%10;
			temp/=10;
		}
		niz[i*2+1]=suma;
	}
}

int izbaci(int niz[], int vel) {
	int *q=niz, *kraj=niz+vel, *poc;
	
	while(q!=kraj) {
		if(provjera(*q)) {
			poc=q;
			while(poc!=kraj-1) {
				*poc=*(poc+1);
				poc++;
			}
			kraj--;
			vel--;
		}
		else q++;
	}
	return vel;
}

int main() {
	
	int niz[100], i, vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<vel; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, vel);
	vel*=2;
	vel=izbaci(niz, vel);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++) {
		if (vel==1) {
			printf("%d.", niz[i]);
		}
		else if(i==0) {
			    printf("%d,", niz[i]);
		}
		else if(i==vel-1) {
			printf(" %d.", niz[i]);
		}
		else {
			printf(" %d,", niz[i]);
		}
	}
	
	return 0;
}