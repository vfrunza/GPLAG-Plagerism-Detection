#include <stdio.h>
#define MAX 100
#define max 1000
int main() {
int niz[MAX],n,brojac=0,b,nb,brojaci[10]={1},i,j;
printf("Unesite velicinu niza: ");
scanf("%d", &n);
printf("Unesite clanove niza: ");
for(i=0;i<n;i++){
	scanf("%d", &niz[i]);
}
printf("Finalni niz glasi: \n");
for(i=0;i<n;i++){
nb=0;
b=niz[i];
for(;;) {if(b==0)break;
nb=nb*10+b%10;
	b=b/10;brojac++;if(b==0){continue;}
}

}
for(i=0;i<brojac;i++){
	niz[i]=b;printf("%d ",niz[i]);
	for(j=0;j<10;j++){
	if(niz[i+1]==b && b==j){brojaci[j]++;printf("%d ",brojaci[j]);}else{ continue;}
}
}
	return 0;
}
