#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int velicina){
	int i, a=0;
	
	for(i=0; i<velicina; i++){
		if(niz[i]<0){
			niz[i]=niz[i]*(-1);
			a=1;
		}
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
		
		if(a==1)
		niz[i]=niz[i]*(-1);
		a=0;
	}
	
}

void preslozi(float niz[], int velicina, int k){
	int i, suma=0, niz_suma[10000], x, p=0, z=0;
	float niz1[1000], niz2[1000];
	
	zaokruzi1(niz,velicina);
	for(i=0; i<velicina; i++){
		
		x=niz[i]*10;
		if(niz[i]<0)
		x=x*(-1);
		while(x>0)
		{
			suma=suma+x%10;
			x=x/10;
		}
		niz_suma[i]=suma;
		suma=0;
	}
	
	for(i=0; i<velicina; i++){
		if(niz_suma[i]>=k){
			niz1[p]=niz[i];
			p++;
		}
		else{
			niz2[z]=niz[i];
			z++;
		}
	}
	
	for(i=0; i<p; i++)
	niz[i]=niz1[i];
	
	for(i=p; i<velicina; i++)
	niz[i]=niz2[i-p];
}

int main() {
	float niz[1000];
	int i, n, k;
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	
	for(i=0; i<n; i++){
	scanf("%f", &niz[i]);
		}
		
		printf("Unesite k: ");
		scanf("%d", &k);
	
	preslozi(niz, n, k);
	for(i=0; i<n; i++)
	printf("%g ", niz[i]);
	
	return 0;
}
