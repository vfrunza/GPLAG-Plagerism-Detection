#include <stdio.h>
#include <math.h>

int main(){
	int niz[100],i,vel,niz1[1000],vel1,niz2[1000],vel2=0;
	int br,x,j,cifra,n;
	int novi;
	
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
}
	while(vel>100 || vel<0);
	printf("Unesite clanove niza: ");
	
	for(i=0;i<vel;i++)
	{
		scanf("%d",&niz[i]);
		if(niz[i]<0) i--;
	}
	vel1=0;
	for(i=0;i<vel;i++)
	{
		br=0;
		x=niz[i];
		if(x==0) {
			niz1[vel1] = x;
			vel1++;
		}
		else{
			while(x>0)
			{
				br++;
				x=x/10;
			}
			novi=0;
			x=niz[i];
			n=br;
			while(x>0)
			{
				cifra=x%10;
				novi=novi+cifra*pow(10,br-1);
				x=x/10;
				br--;
			}
			while(novi>0)
			{
				niz1[vel1]=novi%10;
				novi=novi/10;
				vel1++;
				br++;
			}
			for(j=0;j<n-br;j++){
				niz1[vel1]=0;
				vel1++;
			}
		}
		
	}
	for(i=0;i<vel1;i++)
	{
		x=niz1[i];
		br=0;
		for(j=i;j<vel1;j++)
		{
			if(x!=niz1[j]) break;
			else br++;
		}
		niz2[vel2]=x;
		vel2++;
		niz2[vel2]=br;
		vel2++;
		i=i+br-1;
	}
	printf("Finalni niz glasi:\n");
	for(i=0;i<vel2;i++)
	{
		printf("%d ",niz2[i]);
	}
	return 0;
}