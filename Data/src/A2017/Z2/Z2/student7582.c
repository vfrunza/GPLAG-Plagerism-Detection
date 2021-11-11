#include <stdio.h>
#include <math.h>
int main() {
	int niz[100],i,j=0,n,a[1000],br=0,brojaci[1001]={0},z=0,t=0;
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	
	if(n<=0) return 0;
	
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d", &niz[i]);
	}
	for(i=n-1;i>=0;i--){
		for(;j<1000;j++){
			a[j]=niz[i]%10;
			niz[i]=niz[i]/10;
			br++;
			if(niz[i]==0)
				break;
			
		}
		j=br;
	}
	
	for(i=j-1;i>=0;i--){
		if(z==0){
			brojaci[t]=a[i];
			z++;
		}
		else{
		if(a[i+1]==a[i])
		z++;
		else {
		brojaci[t+1]=z;
		t=t+2;
		brojaci[t]=a[i];
		z=1;
		}
		}
		if(i==0) brojaci[t+1]=z;
	}
		printf("Finalni niz glasi:\n");
		printf("%d", brojaci[0]);
	for(i=1;i<=t+1;i++){
	printf(" %d", brojaci[i]);
	
	}
	return 0;
}
