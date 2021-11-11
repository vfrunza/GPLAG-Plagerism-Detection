#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 2");*/
	int C[100]={0}, i, j, n, K[1000]={0}, b=0, P[1000]={0}, t=0, u=0, l[1000]={0};
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) scanf("%d",&C[i]);
	for(i=n-1; i>=0; i--){
		if(C[i]==0){K[b]=0;b++;}
		while(C[i]>0){
			K[b]=C[i]%10;
			C[i]/=10;
			b++;
		}
	}
	
	for(i=0; i<b; i++) l[i]=K[b-i-1];
	for(i=0; i<b;){
		P[u]=l[i];
		do{
			t++;
			i++;
		} while(l[i-1]==l[i] && i<b);
			u++;
			P[u]=t;
			t=0;
			u++;
	}
	printf("Finalni niz glasi:\n");
	for(i=0; i<u; i++) printf("%d ",P[i]);
	return 0;
}
