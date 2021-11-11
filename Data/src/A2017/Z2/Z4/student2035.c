#include <stdio.h>
#define h 100
#define l 100
int main() {
	int m, n, i, j, vel1=0, minA, minB, minC, temp1, temp2, temp3; //mogla si ovdje imati samo jednu velicinu ali eto
	int matA[h][l], matB[h][l], matC[h][l], nizA[h*l]={0}, nizB[h*l]={0}, nizC[h*l]={0};
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}
	while(n>100 || m>100 || n<0 || m<0);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++) {
	scanf("%d", &matA[i][j]); 
	nizA[vel1]=matA[i][j];
	vel1++;
	}
	vel1=0;
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++) {
	scanf("%d", &matB[i][j]); 
	nizB[vel1]=matB[i][j];
	vel1++;
	}
	vel1=0;
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++) {
	scanf("%d", &matC[i][j]); 
	nizC[vel1]=matC[i][j];
	vel1++;
	}
	
	
	
	for(i=0; i<vel1; i++) {
		minA=i;
		minB=i;
		minC=i;
		for(j=i+1;j<vel1; j++) {
		if(nizA[minA]>nizA[j]) minA=j;
		if(nizB[minB]>nizB[j]) minB=j;
		if(nizC[minC]>nizC[j]) minC=j; }
		
	 	temp1=nizA[i];
	 	nizA[i]=nizA[minA];
	 	nizA[minA]=temp1;
	 	
	 	temp2=nizB[i];
	 	nizB[i]=nizB[minB];
	 	nizB[minB]=temp2;
	 	
	 	temp3=nizC[i];
	 	nizC[i]=nizC[minC];
	 	nizC[minC]=temp3;
	}
	
	for(i=0; i<vel1; i++) {
		if(nizA[i]!=nizC[i] || nizA[i]!=nizB[i]) 
		{
			printf("NE");
			return 0;
		}
	}
	printf("DA");
	return 0;
}
