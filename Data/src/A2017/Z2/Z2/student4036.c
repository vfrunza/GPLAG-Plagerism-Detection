#include <stdio.h>
#define DUZINA1 100
#define DUZINA2 1000
#include <math.h>

int main() {
	int i,j=0,n,broj,nizP[DUZINA1],nizA[DUZINA1],nizB[DUZINA2],nizC[DUZINA2],m,brojac=1,k=0,f,pom,cifre=0,p;
	
	do
	{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n<0 || n>100);	
	
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&broj);
		if (broj<0)
		{
			i--;
			continue;
		}	
		nizA[i]=broj;
	}
	
	for(i=0;i<n;i++)
		nizP[i]=nizA[i];
	
	for(i=0;i<n;i++)
	{

		cifre=0;
		if(nizA[i]==0)
		{
			nizB[j]=0;
			j++;
		}
		while(nizA[i]!=0)
		{
			nizA[i]/=10;
			cifre++;
		}
		if (cifre==1)
		{
			nizB[j]=nizP[i];
			j++;
			continue;
		}
		for(p=0;p<cifre;p++)
		{
			pom=nizP[i]/(int)(pow(10,cifre-1-p)+0.5);
			nizB[j]=pom;
			j++;
			nizP[i]-=pom*(int)(pow(10,cifre-1-p)+0.5);
		}
	}
	
	
	
	m=j;
	for(i=0;i<m;i++)
	{
		if (i==m-1 && nizB[i]==nizB[i-1])
		{
		
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			continue;
		}
		else if (i==m-1 && nizB[i]!=nizB[i-1])
		{
			brojac=1;
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			continue;
		}
		if (nizB[i]==nizB[i+1])
		{
			brojac++;
		}
		if (nizB[i]!=nizB[i+1])
		{
			nizC[k]=nizB[i];
			k++;
			nizC[k]=brojac;
			k++;
			brojac=1;
		}
		
	}
	f=k;
	printf("Finalni niz glasi: ");
	printf("\n");
	for(i=0;i<f;i++)
	{
		printf("%d ",nizC[i]);
	}
	
	return 0;
}

/* nas neki pokusaj nesto 
#include <stdio.h>

int main(){
	int vel, prvi[1000], i, niz[1000], konacni[1000], j=0, velniz, k=0, brojac=0, drugi[1000], cifra1, konac=0 ;
	printf("Unesite velicinu niza: ");
	scanf("%d", &vel);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++){
		scanf("%d ", &prvi[i]);
	}
	
	for(i=0; i<vel; i++){
		cifra1=0;
		while(prvi[i] !=0){
			konac =prvi[i]%10;
			cifra1 = cifra1 *10 + konac; 
			prvi[i] /= 10;
		}
		drugi[i] = cifra1;
		
	}
//	for(i=0; i<vel; i++) printf("obrnuti: %d \n", drugi[i]);
	
	for(i=0; i<vel; i++){
		while(drugi[i] != 0){
			int cifra = drugi[i]%10;
			niz[j]= cifra;
			j++;
			drugi[i]/=10;
		}
	}
	velniz=j;
	printf("velniz: %d", velniz);
	
	/*for(i=0; i<velniz; i++) printf("niz: %d \n", niz[i]);
	
	//nismo bas sigurni, amina... 
	for(i=0; i<velniz; i++){
		brojac=1;
		for(j=i+1; j<velniz; j++){
			if(niz[i] != niz[j]){
				konacni[k]= niz[i]; 
				k++;
				konacni[k]=brojac;
				k++;
				
			}
			else {
				brojac++;
		
			}
		}
	}
	int velk=k;
	for(i=0; i<velk; i++)
		printf("%d ", konacni[i]);
	return 0;
	
}*/