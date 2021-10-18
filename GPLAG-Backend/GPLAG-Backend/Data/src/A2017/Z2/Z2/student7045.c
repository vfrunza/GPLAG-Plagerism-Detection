#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,j,n,vel;
	int brojac,prethodni,temp,obrnut,cifra,viskanula,pomocna;
	int niz[100];
	int novi_niz[1000];
	printf("Unesite velicinu niza: ");
	do 
	{
		scanf("%d", &vel);
	}	while(vel<0 && vel>100); 
	
		printf("Unesite clanove niza: ");
		for(i=0;i<vel;i++)
		{
				scanf("%d", &niz[i]);
				if(niz[i]<0) i--;
		}
	
	brojac=0;
	
		for(i=0;i<vel;i++)
		{
			viskanula=0;
			obrnut=0;
			pomocna=1;
			temp = niz[i];
			if(temp==0) pomocna=0;
			do
			{
				obrnut *= 10;
				obrnut +=temp%10;
				if(temp%10==0 && pomocna==1) viskanula++;
				else if(temp%10 != 0) pomocna=0;
				temp/=10;
			}while(temp!=0);
			
	do
	{
		cifra = obrnut%10;
		
		if(brojac==0)
	{novi_niz[brojac++]=cifra; novi_niz[brojac]=1; }
		else
		{
			if(cifra==novi_niz[brojac-1])
	novi_niz[brojac]++;
		else{
			brojac++;
			novi_niz[brojac++]=cifra;
			novi_niz[brojac]=1;
			}
		}
		obrnut/=10;
	}while (obrnut!=0); 
	
	while(viskanula!=0)
		{
			if(brojac==0) {novi_niz[brojac++]=0;
	novi_niz[brojac]=1; }
		else{
			if(0==novi_niz[brojac-1])
	novi_niz[brojac]++;
		else
		{
			brojac++;
			novi_niz[brojac++]=0;
			novi_niz[brojac]=1;
		}
		
	}
		viskanula--;
		
		}
		
    }
   
  printf("Finalni niz glasi:\n");
  		for(i=0;i<=brojac;i++)
  	printf("%d ",novi_niz[i]);
		
		
		
	return 0;
}
