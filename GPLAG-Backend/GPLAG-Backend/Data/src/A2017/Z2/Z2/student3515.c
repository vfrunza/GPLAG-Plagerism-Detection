#include <stdio.h>
#define BROJ_EL 100
#define BROJ_EL2 1000

int main() {
	int niz[BROJ_EL],brojac[BROJ_EL2],n,i=0,j=0,k=0;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while (n<1);
	printf("Unesite clanove niza: ");
	do{
		scanf("%d",&niz[i]);
		if(i<0) 
			continue;
		i++;
	}
	while (i<n);
	brojac[0]=-1;
	brojac[1]=0;
		for(i=n-1;i>-1;i--)
		{
			do{
				if(brojac[0]==niz[i]%10){ 
				brojac[1]++;
				niz[i]=niz[i]/10;
				continue;
				}else
				{  
				for(j=k-1;j>-1;j--)
				   brojac[j+2]=brojac[j];
				   k+=2;
					brojac[0]=niz[i]%10;
					brojac[1]=1;
					niz[i]=niz[i]/10;
				}
				
			
				
			}while (niz[i]>0); 
		}
				printf("Finalni niz glasi: \n");
				for(i=0;i<k;i++)
				printf("%d ",brojac[i]);
	return 0;
}
