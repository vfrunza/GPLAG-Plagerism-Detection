#include <stdio.h>
#define max 1000
int izbaci_cifre(int niz1[],int vel1,int niz2[], int vel2){
int i,j,cifra,novi=0,k=1,*p=0;
for(i=0;i<vel2;i++){
	if((niz2[i]>9 && niz2[i]<0))return 0;
	else {
			if (niz2[i]==niz2[i+1])return 0; else continue;}
	}
	

for(i=0;i<vel1;i++){
	for(j=0;j<vel2;j++){
		while(niz1[i]!=0){
			cifra=niz1[i]%10;
			if(cifra!=niz2[j])
			{novi=novi+cifra*k;
			k=k*10;}
			niz1[i]/=10;}
			p=novi;
			*p++;
		
		}}
return p;}


int main() {
int niz1[max],niz2[9],i,brojac=0,brojac2=0,x;
printf("Unesite elemente prvog niza: ");
for(i=0;i<max;i++){
	scanf("%d", &niz1[i]);
	if(niz1[i]==-1)break;
	brojac++;
}printf("Elementi drugog niza su: ");
for(i=0;i<max;i++){
	scanf("%d", &niz2[i]);
	if(niz2[i]==-1)break;
	brojac2++;
}
x=izbaci_cifre(niz1,brojac,niz2,brojac2);
printf("%d",x);
	return 0;
}
