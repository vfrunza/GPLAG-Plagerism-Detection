#include <stdio.h>

/*int main() {
	int C[100],drugi[100],treci[1000],k,temp,velA,cifra[1000],vel;
	int velicina,i,j,brojac[101]={0};
	printf("Unesi velicinu niza: ");
	scanf("%d",&velicina);
	printf("Unesi elemente niza ");
	for(i=0;i<velicina;i++)
	{
		scanf("%d",&C[i]);
		if(C[i]<0)
		{
			printf("Greska!\n");
			scanf("%d",&C[i+1]);
		};
	
	if(C[i]>0 && C[i]<10)
	{
		cifra[i]=C[i];
		velA++;
		
	}
	else
	{
while(C[i]>0){
cifra[i]=C[i]&10;
	C[i]/=10;
	velA++;
}
	}	


	
}
for(i=0;i<velicina;i++)
printf("%d",cifra[i]);
	

	


	printf("Finalni niz glasi: \n");
	

	
	
	
	return 0;
}*/
int main(){
	int n,i,j,k,niza[100],nizc[200]={0},brojac=0,velc=0,nizb[100]={0};
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d",&niza[i]);
		if(niza[i]<=0){
			printf("Greska!");
			i--;
		}
		
	}
	int d=0,z=0,t=0;
	for(i=0;i<n;i++){
		d=0;
		while(niza[i]>0){
			d=niza[i]%10;
			z++;
			nizd[z]=d;
			niza[i]/=10;
		}
		t=z;
		for(j=t;j>0;j--)nizb[]
	}
	for(i=0;i<z;i++)
	printf("%d",nizb[i]);
	/*
	for(i=0;i<z;i++){
		brojac=1;
		k=i+1;
		while(nizb[i]==nizb[k]){
			brojac++;
			k++;
		}
		nizc[i]=nizb[i];
		j=i+1;
		nizc[j]=brojac;
		velc+=2;
	}
	printf("Finalni niz glasi: ");
	for(i=0;i<velc;i++){
		printf("%d ",nizc[i]);
	}*/
	return 0;
}