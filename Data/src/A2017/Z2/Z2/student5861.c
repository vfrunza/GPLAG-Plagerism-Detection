#include <stdio.h>

int main() {
	int nizA[100], nizB[1000], nizP[1000];
	int i, j, brojac=0, brojac1=1, brojac2=0;
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &j);
	printf("Unesite clanove niza: ");
	
	for(i=0;i<j;i++)
	scanf("%d", &nizA[i]);
	
	for(i=j-1; i>=0; i--){
		if(nizA[i]==0)
		{
			nizP[brojac]=0;
			brojac++;
		} else {
			while(nizA[i]>0)
			{
				nizP[brojac]=nizA[i]%10;
				nizA[i]=nizA[i]/10;
				brojac++;
			}
			
		}
	}
	
	nizB[0]=nizP[brojac-1];
	
	for(i=brojac-1; i>0; i--) {
		if(nizP[i]==nizP[i-1]){
			brojac1++;
		} else {
			nizB[brojac2+1]=brojac1;
			brojac2=brojac2+2;
			brojac1=1;
			nizB[brojac2]=nizP[i-1];
		}
	}
	brojac2=brojac2+2;
	nizB[brojac2-1]=brojac1;
	
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<brojac2; i++)
	{
		printf("%d ", nizB[i]);
	}
	return 0;
}
