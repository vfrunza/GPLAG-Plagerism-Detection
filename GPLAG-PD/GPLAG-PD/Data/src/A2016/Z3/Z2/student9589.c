#include <stdio.h>
void ubaci(int niz[],int n){
	int i;
	int broj;
	int niz1[1000];
	int niz2[1000];
	int suma=0;
	int k=0,s=0;
	for(i=0;i<n;i++){
		broj=niz[i];
		suma=0;
		if(broj<0){
			broj*=-1;
		}
		
		while(broj>0){
			suma+=broj%10;
			broj/=10;
		}
		niz1[i]=suma;
		
	}
	while(k!=2*n){
		niz2[k++]=niz[s];
		niz2[k++]=niz1[s];
		s++;
	}
	for(i=0;i<2*n;i++){
		niz[i]=niz2[i];
	}

	
	

		

	
	
}
int izbaci(int niz[],int n){
int i,j,l,k=0;
int suma=0;

for(i=0;i<n;i++){
	suma=0;
k=0;
l=1;
while(1){
	suma=k+l;
	k=l;
	l=suma;
	if(suma==niz[i]||suma>niz[i]){
		break;
	}
	
}
if(niz[i]==suma){
	for(j=i;j<n-1;j++){
		niz[j]=niz[j+1];
	}
	n--;
	i--;
	
}
	
}
return n;

	



}

int main() {
	int i;
	int niz[2000];
	int vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
	scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
 vel=izbaci(niz,20);
printf("Modificirani niz glasi: ");
for(i=0;i<vel;i++){
	printf("%d",niz[i]);
	if(i!=vel-1){
		printf(", ");
	}
	else printf(".");
}
	
	

	return 0;
}
