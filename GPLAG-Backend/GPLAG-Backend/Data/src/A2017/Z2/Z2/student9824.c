#include <stdio.h>
#include <math.h>

int main() {
	int velicina[100],brojac1[150];
	int i,n,niz,cifra,brojac2=0,prolaz=0;;
	float floatniz;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%f",&floatniz);
		niz=floatniz;
		if(niz<=0 || floatniz - niz >0){
        printf("Neispravna veilcina niza!\n");		
	}
	else
	n=niz;
}while(niz<=0 || floatniz - niz>0);

do{
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%f",&floatniz);
		niz=floatniz;
		
		if(niz<0 || floatniz - niz>0){
			printf("Neispravan clan niza!\n");
			break;
		}
		else
		{
			velicina[i]=niz;
			if(i==n-1)
			prolaz==1;
		}
	}
}while(prolaz==1);
for(i=0;i<n;i++){
	niz=velicina[i];
	cifra=0;
	
	if(niz==0){
		brojac1[brojac2++]=0;
	}
	else
	{
		while(niz!=0)
	{
		cifra++;
		niz /=10;
	}
	niz=velicina[i];
	while(cifra>0){
		brojac1[brojac2++]=niz/pow(10,cifra-1);
		niz=niz%(int)pow(10,cifra-1);
		cifra--;
	}
}
}
printf("Finalni niz glasi: \n");
for(i=0;i<brojac2;i++){
	printf("%d ",brojac1[i]);
	cifra=1;
	if(i==brojac2-1)	;
	else{
		while(brojac1[i]==brojac1[i+1]){
			cifra++;i++;
			if(i+1>=brojac2)
			break;
		}
	}
	if(i==brojac2-1)
	printf("%d",cifra);
	else{
		printf("%d ",cifra);
	}
}
return 0;}

	
	
   