#include <stdio.h>

int main()
{
	int i;
	int n;
	int nizA[100];
    int	nizB[1000];
	int nizC[1000];
	int Brojac=0;
	int br=1;
	int k=0;

	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");

	for(i=0; i<n; i++) {
		scanf("%d",&nizA[i]);
	}
	for(i=n-1; i>=0; i--) {
		if(nizA[i]==0) {
			nizC[Brojac]=0;
			Brojac++;
		} else {
			while(nizA[i]>0) {
				nizC[Brojac]=nizA[i]%10;
				nizA[i]=nizA[i]/10;
				Brojac++;
			}
		}
	}
	nizB[0]=nizC[Brojac-1];
	for(i=Brojac-1;i>0;i--){
		if(nizC[i]==nizC[i-1]){
			br++;
		}
		else{
			nizB[k+1]=br;
			k=k+2;
			br=1;
			nizB[k]=nizC[i-1];
		}
	}
	
	k=k+2;
	nizB[k-1]=br;
	printf("Finalni niz glasi:\n");
	for(i=0;i<k;i++)
	{
		printf("%d ",nizB[i]);
	}

	return 0;
}
