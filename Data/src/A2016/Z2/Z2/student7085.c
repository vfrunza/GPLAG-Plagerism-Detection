#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define  PI 3.1415926

int main() {
	int i,j,stepeni[500],sek[500],min[500],n,p;
    double pret[500],niz[500],k,ostatak;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
	scanf("%lf",&niz[i]);}

	
	for(i=0;i<n;i++){
	pret[i]=fabs(niz[i]*180./PI);
	p=pret[i]*3600;
	k=pret[i]*3600;
	ostatak=k-p;
	if(ostatak>0.5)
	p++;
	stepeni[i]=p/3600;
	min[i]=fabs((p%3600)/60);
	sek[i]=(p%3600)%60;
	
	if(sek[i]>30){
	for(j=i;j<n;j++){
		pret[j]=pret[j+1];
		niz[j]=niz[j+1];
		stepeni[j]=stepeni[j+1];
		min[j]=min[j+1];
		sek[j]=sek[j+1];}
		i--;
		n--;
	}	
	}
	printf("Uglovi su:\n");
		
	for(i=0;i<n;i++){
		if(niz[i]<0)
		printf("-%d stepeni %d minuta %d sekundi\n",stepeni[i],min[i],sek[i]);
		else
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], min[i], sek[i]);
	}	
	
	return 0;
}
